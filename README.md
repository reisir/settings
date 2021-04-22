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

## TO-DO for release:
 - [x] Update RainDoc wiki to new Pipe syntax
 - [x] Write an example.inc
 - [x] Make the generated skin look nicer
   - [x] Add a bit of padding to the top of the category list
   - [x] Make all string meters `ClipString=2`
   - [x] Move Credit.inc from the first page to the bottom of the list
 - [x] Add a scroll indicator
 - [x] Update generator.ini to match new templates
   - [x] Add links to guides in generator.ini
 - [x] Flip the toggle buttons

## TO-DO:
 - [x] Streamline the generation sequence, maybe make Settings "inject" the generated settings skin into the target skin
   - [x] Make construct.ps1 !RefreshApp and load the generated skin without errors.
   - [ ] Make the user hold alt or something to Inject automatically.
 - [x] Link syntax Display=Target
 - [x] Add a way to refresh the right skin when variables are changed
    - [x] Add a way to specify a custom bang to run when variables are changed
 - [x] Guide on overriding internal Settings `[#s_]` variables
   - [x] Can now just generate internal Settings settings skin.. because duh
 - [x] Generate generator.ini
   - [x] Reconsider.
 - [ ] Refactor `Pipe-Variable` and `Pipe-Category`
 - [ ] Slider template
 - [ ] Write wiki for templates
   - [ ] Dynamically get list of templates for $implementedTypes
   - [ ] Dynamically include all includes in Rainmeter.inc template
 - [ ] Add icon support for variables. Then move descriptions to X=0r instead of relying on the padding being the same
 - [ ] Better (custom ?) colour picker
 - [ ] Document Tooltip
   - [ ] Make it work first
 - [ ] Make list items rely on actual padding for ClipString instead of complicated width calculations 
 - [ ] Proofread the wiki
 - [ ] Another way to select file other than Drag & Drop
 - [ ] Add way to change the icon font per Icon

