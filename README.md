# Settings

Settings skin generator skin. Creates a settings skin from a JSON object.

## Notes to self:

The settings skin consists of variant skins which all have the categories menu included. The categories menu is controlled with #Selected#.

## Skin structure example:

### JSON

```json
{
    Settings : {
        Title : "Example skin",
        Subtitle : "An example settings skin generated with Settings Skins generator",
        Description : "",
        VariablesFile : "settings.inc"
    },
    Colors : {
        Variables : {
            0 : {
                Type : "Color",
                DefaultValue : "FFFFFF",
                Name : "FontColor"
            },
            1 : {
                Type : "Color",
                DefaultValue : "696969",
                Name : "BackgroundColor"
            },
            2 : {
                Type : "Color",
                DefaultValue : "255,0,0",
                Name : "WarningColor"
            }
        }
    },
    Size : {
        Variables : {
            0 : {
                Type : "Percent",
                DefaultValue : "100",
                Variable : "SCALE",
                Name : "Scale"
            },
            1 : {
                Type : "Integer",
                DefaultValue : "80",
                Name : "Bars"
            },
            2 : {
                Type : "Number",
                DefaultValue : "120",
                Name : "Height"
            },
            3 : {
                Type : "Angle",
                DefaultValue : "90",
                Variable : "Angle",
                Name : "Rotation"
            }
        }
    }
}
```

### Outputted skin structure

* Skins\Settings Generator
  * @Resources
    * Includes\
    * settings.inc
    * generateSettings.ps1
  * Settings
    * Settings.ini
    * Colours.ini
    * Size.ini