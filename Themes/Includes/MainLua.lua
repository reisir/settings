function OnChangeAction()
    BangVar('s_SaveScroll')
    BangVar('s_OnChangeAction')
end

function BangVar(varName) SKIN:Bang(SKIN:ReplaceVariables(SKIN:GetVariable(varName))) end

function Ternary(value, comparisonType, equalValue, trueValue, falseValue)

    --Sees if value, comparisonType or equalValue is to be parsed or used as is.
    if string.match(value, '^%{(.*)}$') then value=FormulaParser(value) value=tostring(value) end

    if string.match(equalValue, '^%{(.*)%}$') then equalValue=FormulaParser(equalValue) equalValue=tostring(equalValue) end

    --If user wants to use { } at the ends without wanting to evaluate the formula.
    if string.match(value, '^\\%{.*\\%}$') then value=string.gsub(value, '^\\%{(.*)\\%}$', '{%1}') end

    if string.match(equalValue, '^\\%{.*\\%}$') then equalValue=string.gsub(equalValue, '^\\%{(.*)\\%}$', '{%1}') end
        
    --converts strings to numbers to apply relational operators
    local x=comparisonType
    if x~='EqualsTo' and x~='=' and x~='NotEquals' and x~='!=' then value=tonumber(value) equalValue=tonumber(equalValue) end

    --main function
    if comparisonType == 'EqualsTo' or comparisonType == '=' then
        if value == equalValue then
            return trueValue
        else
            return falseValue
        end
    elseif comparisonType == 'GreaterThan' or comparisonType == '>' then
        if value > equalValue then
            return trueValue
        else
            return falseValue
        end
    elseif comparisonType == 'GreaterThanEquals' or comparisonType == '>=' then
        if value >= equalValue then
            return trueValue
        else
            return falseValue
        end
    elseif comparisonType == 'LessThan' or comparisonType == '<' then
        if value < equalValue then
            return trueValue
        else
            return falseValue
        end
    elseif comparisonType == 'LessThanEquals' or comparisonType == '<=' then
        if value <= equalValue then
            return trueValue
        else
            return falseValue
        end
    elseif comparisonType == 'NotEquals' or comparisonType == '!=' then
        if value ~= equalValue then
            return trueValue
        else
            return falseValue
        end
    end
end

function MatchTernary(string, matchType, regexVar, trueValue, falseValue)

    --gets the regex pattern variable
    regexPattern=SKIN:GetVariable(regexVar)

    --main function
    if matchType == 'match' then
        if string.match(string, regexPattern) then
            return trueValue
        else
            return falseValue
        end
    elseif matchType == 'notmatch' then
        if not string.match(string, regexPattern) then
            return trueValue
        else
            return falseValue
        end
    elseif matchType == 'contains' then
        if string.find(string, regexPattern) then
            return trueValue
        else
            return falseValue
        end
    elseif matchType == 'notcontains' then
        if not string.find(string, regexPattern) then
            return trueValue
        else
            return falseValue
        end
    end
end

function FormulaParser(arg)
    arg=string.gsub(arg, '^%{(.*)%}$', '(%1)')
    return SKIN:ParseFormula(arg)
end