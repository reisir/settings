[Rainmeter]
DefaultUpdateDivider=-1
@IncludeSkinVariables=#ROOTCONFIGPATH#settings\skinVariables.inc
@IncludeSettingsStyles=#ROOTCONFIGPATH#settings\includes\VarStyles.inc

[Variables]
s_CurrentCategory=0

[IncludeBackground]
@IncludeCategory=#ROOTCONFIGPATH#settings\includes\Background.inc

[IncludeCategoryList]
@IncludeCategoryList=#ROOTCONFIGPATH#settings\categories\CategoryList.inc

[IncludeCategory]
@IncludeCategory=#ROOTCONFIGPATH#settings\categories\[#s_CurrentCategory].inc
