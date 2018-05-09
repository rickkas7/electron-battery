# Electron Battery Tips

*Some handy bits of code for special Electron battery situations*

There are three code examples:

## no-battery

This example is for when you have nothing connected to the Li+ or JST battery connected. It disables the red charging LED so it doesn't blink. It also disconnects the battery so nothing will happen if you plug one in.

## no-charging

This disables the red charging LED, and also disables charging. This is useful if you connect a non-rechargeable battery to Li+/JST.

## reset-pmic

Some of the settings in the bq24195 PMIC are non-volatile. This program resets them to the standard values. You should only do this when you think the settings are screwed up, you should not set the settings every time you use the device.

