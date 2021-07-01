# Settings

Settings is a Rainmeter skin that generates settings skins for other Rainmeter skins.

# Disclaimer

# :warning: I'm currently rewriting the generator so DO NOT clone this repository and expect it to work. Use the latest version in [Releases](https://github.com/sceleri/settings/releases) :warning:

### :warning: When you use the generator, all .inc, .ini and .exe files in "yourskin\settings" are deleted and replaced :warning:

# Using Settings

## Pre-requisites

- Format your variable file with [RainDoc](https://github.com/sceleri/settings/wiki/RainDoc-syntax) syntax.
  - Check out the [quick-start guide](https://github.com/sceleri/settings/wiki) for a guide and example of a simple variable file.

## Generating settings skins

1.  Drag & Drop your formatted variable file on the generator skin.
2.  Click on Generate.

- This deletes files in "yourskin\settings". Including any skins you had there or modifications you made to an earlier generated skin.

## TO-DO:

- [ ] Dynamically get list of templates for $implementedTypes
  - [ ] Check if type is implemented before attempting run script
  - [ ] Dynamically include all includes in Rainmeter.inc template
- [x] Add safety newlines after variable templates
- [ ] Redo the Settings skins probably separately from the generated skins styles etc
- [ ] Script based templates
  - [ ] Each script receives a variable object with index
  - [x] Move Variable.Properties... to Variable...
- [ ] Clamp based scrolling
  - [ ] Figure out a better way to make the scroll indicator work
- [ ] Always use trailing slashes in paths
- [ ] Log errors ? Error rendering template ?
- [ ] Refactor `Pipe-Variable` and `Pipe-Category`
  - [ ] Make categories and variables have Name defaulted to Key if Name not found during parsing
    - This is mostly because I want the error logs to have access to the Name
- [ ] Hold alt to override auto-inject?
- [ ] Test if file needs to be in @Resources or a subdirectory
- [ ] Make the "delete all files" red when hovering over "Generate & Inject"
- [ ] Template stuff
  - [ ] Document templates
  - [ ] Slider template
  - [ ] Image template
- [ ] Documentation
  - [ ] Write more examples for the wiki
  - [ ] Proofread the wiki
  - [ ] Document Tooltip
    - [ ] Make it work first
- [ ] Invert property for toggles
  - [ ] Maybe just use `[\xF19E]` and `[\xF19F]` for toggles?
- [ ] Make variables use `ClipStringW` instead of `W` so death.crafter stops complaining about clicking on them
- [ ] Selected indicator doesn't take scrolling into account
- [ ] Change the version in rainmeter.inc template
- [ ] Internal settings
  - [ ] Reset s_OnChangeAction before release
  - [ ] Close button
    - [ ] Set category back to 0
    - [ ] Way to set the default category
  - [ ] Toggle for variable indenting
- [ ] Better (custom ?) colour picker that can handle alpha
- [ ] Make a better way to disable the changing of variables
  - [ ] Figure out what this was about
- [ ] Another way to select file other than Drag & Drop
- [ ] Add way to change the icon font per Icon
- [ ] Separate generator tabs into their own skins? Make Settings into a suite just for building settings skins?
