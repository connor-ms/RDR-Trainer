# RDR-Trainer
A simple script trainer for Red Dead Redemption. Meant to be a base to build off of and add more features to.

![Screenshot of menu](.github/screenshot.png?raw=true "Screenshot of Menu")

# Download
For the latest download, navigate to the releases tab, or click [here](https://github.com/connorms/RDR-Trainer/releases).

## Features
It's not a very feature-filled menu, because it's only meant to be a starting point to be built off of. Here's the list of current features though that are already included:
  - Self options
    - Invincible
    - Invisible (server-side only)
    - Noclip
    - Drunk
  - Weapon Options
    - Give All Weapons
    - Toggle All Weapons Gold
    - Infinite Ammo
  - World Options
    - Set Weather
  - Teleporter
    - Teleport to Location
    - Teleport 2ft in Direction
  - Vehicle Spawner
    - Spawn Vehicle
  - Animal Spawner
    - Set Animal
      - Invincible
      - Rideable
      - Bodyguard
      - Auto Ride
    - Spawn Animal
  - Network Options
    - Fix Server
    - Level Spoofer
    - Refresh Playerlist
    - Player Options
      - Teleport to
      - Teleport to me (experimental)
      - Explode
      - Spectate
      - Kill Horse (not working)
  - Script Loader
    - Load Script

## Building
1. Download and install Git.
2. Open command prompt and type:
    ```
    git clone --recursive-submodules https://github.com/connorms/RDR-Trainer
    ```
3. Navigate to the cloned repository -> tools and run the batch file depending on if you want to build for PS3 or Xbox 360.
4. The output script file will be in `/bin/menu.(x/c)sc` (file extension depends on whether it was built for PS3 or 360).

## Installing
1. Use an RPF editor of your choice.
2. In the main RPF (usually either `rdr2_layer0.rpf` or `patch0_ps3.rpf`, but can vary depending on game version/console/etc.), navigate to `/content/release/scripting/DesignerDefined/ui/`.
3. Extract `fuieventmonitor.(x/c)sc`, rename it to `fuieventmonitor_o.(x/c)sc`, and import it back into the same directory.
4. Rename this script to `fuieventmonitor.(x/c)sc` and import it into the same directory. NOTE: If you're on Xbox, use `.xsc`. If you're on PS3, use `.csc`.
5. Save and rebuild the RPF, and replace the modified RPF with the original one on the console.

## How to use script loader
To use the script loader, rename your script to a number that's 1-10 (while keeping original extension), and place it in `/content/release/scripting/`. In game, go to the script loader and select the number that corresponds to your script.