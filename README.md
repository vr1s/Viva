# HomePlus Pro

Compiled versions available at:
https://repo.chariz.com/

This source code is shared for a couple reasons:
* Users should be able to know what code is being ran on their device
* Developers should be able to see how to (debatably) correctly interact with private APIs

A note to developers:
I've found absolutely zero impact on sales when doing this in the past, nobody stole+rebranded my tweak, and everything was fine. 
I don't expect everyone to open source paid tweaks but I see no reason not to.

## Extensions:
Extensions are custom views that allow configuring the preferences of other tweaks, live, from within the HomePlus UI.

Any dev can easily add support to their tweak, and no code is required.

[info for developers here](https://github.com/KritantaDev/HomePlusPro/blob/master/HomePlusEditor/Extensions/README.md)

## What's missing from this?
I've commented explanations for every item in .gitignore, but I'll walk through the major ones here:

* Image assets (the HPResources bundle) These are included in the compiled .deb available on chariz
* DragonMake build script (temporary)
* Preference folder (nothing in it, temporarily excluded)
* HomePlus.x; there's no "useful to jailbreak devs" code in here; it's all been moved elsewhere. Among other things

> So can I compile this and run it?

not yet. I'm working on it and it's absolutely a goal

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

