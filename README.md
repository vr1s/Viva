# HomePlus Pro

HomePlus Pro is a powerful, featherweight, and extensible homescreen layout and modification tweak for iOS 13-16

## Extensions:
Extensions are custom views that allow configuring the preferences of other tweaks, live, from within the HomePlus UI.

Any dev can easily add support to their tweak, and no code is required.

[info for developers here](https://github.com/KritantaDev/HomePlusPro/blob/master/HomePlusEditor/Extensions/README.md)

## Project Layout

HomePlusEditor/ - Non-hook class files for the HomePlus UI, managers, and otherwise

Hooks/ - (guess what type of code is in this folder)

### ./HomePlusEditor/

#### > Data/

houses HPConfiguration which is an in house replacement for using NSUserDefaults to store config values

#### > EditorUI/

Pretty much the entirety of code related to the editor UI

#### > Extensions/

HomePlus Pro Extension support code

#### > Hitbox/

Unfinished replacement for GestureRecognizer.xm

#### > Managers/

Several somewhat reduntant "sharedInstance"-type classes that code throughout the tweak communicates via.

#### > Settings/

Settings view stuff. 

#### > Utility/

functions/classes that didn't quite belong elsewhere

### ./Hooks

Hooks

#### > ios14

There used to be version specific folders. As it stands the code i've written now doesn't require that afaik

I'll move it around after release.

