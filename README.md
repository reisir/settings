# Settings

Settings is a Rainmeter skin that generates settings skins for other Rainmeter skins.

It reads the target skins `settings.inc` file and generates meters and measures to both display and change the variables. 

## Usage

1. Drag & Drop your settings.inc on the generator skin.
2. Confirm that the right skin and file is selected.
3. Click on Generate.
   * This will remove any previous files in the settings directory.

A generated settings skin should open. You can test it and confirm it's changing the right file. If it works, move the folder called "settings" from `Skins\Settings` to `Skins\YourSkin`.

If the generated skin looks like ass, [RTFM](https://github.com/sceleri/settings/wiki)

## TO-DO:
 - [ ] Update RainDoc wiki to new Pipe syntax
 - [x] Write an example.inc
 - [ ] Write wiki for templates
 - [ ] Refactor `Pipe-Variable` and `Pipe-Category`
 - [ ] Add a way to refresh the right skin when variables are changed
    - [ ] Maybe add a way to specify a custom bang to run when variables are changed
 - [x] Make the generated skin look nicer
 - [ ] Another way to select file other than Drag & Drop
 - [ ] Add icon support for variables. Then move descriptions to X=0r instead of relying the padding being the same

