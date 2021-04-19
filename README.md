# Settings

Settings is a Rainmeter skin that generates settings skins for other Rainmeter skins.

## Basic usage

1. Read the [quick-start guide](https://github.com/sceleri/settings/wiki) on how to format the generated skin. Settings will not work if you don't format your variable file correctly.
2. Format your variable file.
3. Drag & Drop your variable file on the generator skin.
4. Click on Generate.
5. Click on "Open skin".
6. Test that the generated skin works and is actually changing the variables.
   * You have to refresh your skin manually after changing variables with Settings.
7. Move the folder called "settings" from `Skins\Settings` to `Skins\YourSkin`.
8. Right click the Rainmeter tray icon and Refresh all.

Steps 4-8 will be combined into one step in a later release.

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
 - [ ] Streamline the generation sequence, maybe make Settings "inject" the generated settings skin into the target skin

