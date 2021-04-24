# Settings

Settings is a Rainmeter skin that generates settings skins for other Rainmeter skins.

# Disclaimer

### :warning: When you use the generator, all .inc,.ini and "RainRGB4RunCommand.exe" files in "yourskin\settings" are deleted and replaced :warning:

# Using Settings

## Pre-requisites

 * Format your variable file with [RainDoc](https://github.com/sceleri/settings/wiki/RainDoc-syntax) syntax.
   * Check out the [quick-start guide](https://github.com/sceleri/settings/wiki) for a guide and example of a simple variable file.

## Generating settings skins

 1. Drag & Drop your formatted variable file on the generator skin.
 2. Click on Generate.
   * This deletes files in "yourskin\settings". Including any skins you had there or modifications you made to an earlier generated skin.

## TO-DO for v1.2 release:
 - [x] Fix InputText sizing
 - [x] Add a way to refresh the right skin when variables are changed
    - [x] Add a way to specify a custom bang to run when variables are changed
 - [x] Handle unformatted files
 - [x] Link syntax Display=Target
 - [x] Add icon support for variables. Then move descriptions to X=0r instead of relying on the padding being the same
   - [x] Update wiki to match
 - [x] Frosted glass plugin
 - [x] Themes
   - [ ] Dark theme
   - [ ] Slim theme
 - [x] Make the skin !Log if you have a typo (only for Type atm)
 - [x] Streamline the generation sequence, maybe make Settings "inject" the generated settings skin into the target skin
   - [x] Make construct.ps1 !RefreshApp and load the generated skin without errors.

## TO-DO:
 - [ ] Refactor `Pipe-Variable` and `Pipe-Category`
   - [ ] Make categories and variables have Name defaulted to Key if Name not found during parsing
       * This is mostly because I want the error logs to have access to the Name
 - [ ] Make a better way to disable the changing of variables
 - [ ] Invert property for toggles
 - [ ] Dynamically get list of templates for $implementedTypes
   - [ ] Dynamically include all includes in Rainmeter.inc template 
 - [ ] Hold alt to override auto-inject?
 - [ ] Improve the theme system, move theming variables outside of internal variables.
 - [ ] Slider template
 - [ ] Toggle for variable indenting
 - [ ] Write wiki for templates
 - [ ] Write more examples for the wiki
 - [ ] Better (custom ?) colour picker that can handle alpha
 - [ ] Document Tooltip
   - [ ] Make it work first
 - [ ] Proofread the wiki
 - [ ] Another way to select file other than Drag & Drop
 - [ ] Add way to change the icon font per Icon

