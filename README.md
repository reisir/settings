# Settings

Settings is a Rainmeter skin that generates settings skins for other Rainmeter skins.

It reads the target skins variable file and generates meters and measures to both display and change the variables. 

## Basic usage

Drag & Drop your settings.inc on the generator skin.

Confirm that the right skin and file is selected.

Click on Generate.
   * This will remove any previous files in the settings directory.

A generated settings skin should open. You can test it and confirm it's changing the right file.

Read the [quick-start guide](https://github.com/sceleri/settings/wiki) on how to customize the generated skin.

Once you're done, move the folder called "settings" from `Skins\Settings` to `Skins\YourSkin`.

## TO-DO for release:
 - [x] Update RainDoc wiki to new Pipe syntax
 - [x] Write an example.inc
 - [ ] Make the generated skin look nicer
   - [x] Add a bit of padding to the top of the category list
   - [x] Make all string meters `ClipString=2`
   - [x] Move Credit.inc from the first page to the bottom of the list
 - [x] Add a scroll indicator
 - [x] Update generator.ini to match new templates
   - [x] Add links to guides in generator.ini
 - [x] Flip the toggle buttons

## TO-DO: 
 - [ ] Link syntax Display=Target
 - [ ] Write wiki for templates
 - [ ] Refactor `Pipe-Variable` and `Pipe-Category`
 - [ ] Add a way to refresh the right skin when variables are changed
    - [ ] Maybe add a way to specify a custom bang to run when variables are changed
 - [ ] Another way to select file other than Drag & Drop
 - [ ] Add icon support for variables. Then move descriptions to X=0r instead of relying on the padding being the same
 - [ ] Guide on overriding internal Settings `[#s_]` variables
 - [ ] Add way to change the icon font per Icon
 - [ ] Slider template
 - [ ] Generate generator.ini
 - [ ] Better (custom ?) colour picker
 - [ ] Document Tooltip
 - [ ] Make list items rely on actual padding for ClipString instead of complicated width calculations 

