--------------------------------- Arduino Digital Clock ---------------------------------

This project is a digital clock implemented using an Arduino and an LCD display.  
It displays hours, minutes, and seconds, and allows manual time setting using two push buttons.

## Features

- Displays time in hours, minutes, and seconds.
- Button on pin 2: Reset button.
- Button on pin 3: Mode button.
- Pressing Reset for 3 seconds enters time-setting mode.
- In setting mode:
  - Short press on Mode cycles through seconds → minutes → hours.
  - Pressing Reset:
    - Resets seconds to 0 (in seconds setting),
    - Increments minutes or hours (in respective setting modes).
  - Long press on Mode exits setting mode.

Time continues running in the background even during the adjustment mode.
