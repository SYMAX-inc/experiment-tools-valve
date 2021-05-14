This is solenoid valve controller hardware and firmware.

# Schematics
See [inventhub](https://inventhub.io/c/dodo5522/experiment-tools-valve/blob?branchName=master&repoId=609de461cc8df700c7a5a347&hash=cca0b92a0ec4ed1b5e4ae2807843b0632ecae068&path=schematics/experiment-tools-valve.sch&cacheLib=experiment-tools-valve-cache.lib&cacheLibHash=d32a24f3663cecf26f33193b94d324d6a58c2372).

# How to build and install
1. Install [Arduino IDE](https://www.arduino.cc/en/software) (recommend 1.8.12)
1. Add URL https://kimio-kosaka.github.io/digispark-clone/package_digispark-clone_index.jsonhttps://kimio-kosaka.github.io/digispark-clone/package_digispark-clone_index.json into `Boards Manager URLs` on Preferences of Arduino IDE
    - For more detail, refer to [digispark-clone github](https://github.com/kimio-kosaka/digispark-clone)
1. Install `Disispark AVR Boards (clone)` on Boards Manager on Arduino IDE
1. Select `Digispark (Default - 16.5mhz)` on menu `Tools -> Boards` of Arduino IDE
1. Select `Micronucleus` on menu `Tools -> Programmers` of Arduino IDE
1. Open [experiment-tools-valve.ino](./experiment-tools-valve.ino) on Arduino IDE
1. Disconnect USB cable from solenoid valve board
1. Push `Upload` button on Arduino IDE
1. Connect USB cable to solenoid valve board and wait a while
1. Succeeded with below log message

    ```
    running: 100% complete
    Micronucleus done. Thank you!
    ```
