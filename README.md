# Settings

Settings is a Rainmeter skin that generates settings skins for other Rainmeter skins.

# I'm currently rewriting the generator so DO NOT clone this repository and expect it to work. Use the latest version in [Releases](https://github.com/sceleri/settings/releases)

## The syntax will not change, so if you format your variable files now, they will still work.

# Using Settings

## Pre-requisites

- Format your variable file with [RainDoc](https://github.com/sceleri/settings/wiki/RainDoc-syntax) syntax.
  - Check out the [quick-start guide](https://github.com/sceleri/settings/wiki) for a guide and example of a simple variable file.

## Generating settings skins

1.  Drag & Drop your formatted variable file on the generator skin.
2.  Click on Generate.

### :warning: This deletes files in "yourskin\settings". Including any skins you had there or modifications you made to an earlier generated skin.

## TODO:

- [ ] Make UsePlugin work
- [ ] Log errors ? Error rendering template ?
  - Show the exact line of potential error ?
- [ ] Make categories and variables have Name defaulted to Key if Name not found during parsing
  - This is mostly because I want the error logs to have access to the Name
- [ ] Make the "delete all files" red when hovering over "Generate & Inject"
- [ ] Documentation
  - [ ] Write more examples for the wiki
  - [ ] Proofread the wiki
- [x] Better (custom ?) colour picker that can handle alpha
  - [x] Ability to type in color values
- [x] Another way to select file other than Drag & Drop
- [x] Refactor `Pipe-Variable` and `Pipe-Category`
- [x] Toggle for auto-inject
- [x] Fix file needing to be in @Resources or its subdirectory to generate properly
- [x] Get rid of the internal settings skin, not needed
- [x] Separate generator tabs into their own skins? Make Settings into a suite just for building settings skins?
- [x] Redo the Settings generator skins separate from the generated skins styles etc
- [x] Check if containers can be taller than their contents without affecting flow
  - It affects flow
- [x] LeftMouseUpAction override instead of using info variables
- [x] Add way to change the icon font per Icon
  - [ ] Link to sl23's icon collection skin
- [x] Make the skin remember the scroll position when variables are changed and the skin is refreshed
- [x] Change the version in rainmeter.inc template
- [x] Figure out a better way to make the scroll indicator work
  - It's not better but it works
- [x] Close button
- [x] Implement scrolling again
- [x] Make variables use `ClipStringW` instead of `W` so death.crafter stops complaining about clicking on them
- [x] Selected indicator doesn't take scrolling into account
  - Fixed by making a selected indicator for each list item
- [x] Rename VarContainer etc to VariableContainer
- [x] Padding between items and icons
- [x] Fix InputText position
- [x] Font Property
- [x] Script based templates
  - [x] Each script receives a variable object with index
  - [x] Move Variable.Properties... to Variable...
- [x] Handle unformatted variable files (just logs error for now)
- [x] Combine meterstyles from separate files into one big file and @Include that to the main .ini
- [x] Dynamically get list of templates for $implementedTypes
- [x] Add safety newlines after variable templates
- [x] Invert property for toggles
  - [x] Maybe just use `[\xF19E]` and `[\xF19F]` for toggles?
    - Doesn't work :(
- [ ] Check that all of the items in this list actually work
