# WebBluetooth-Terminal

A serial terminal based on the newly released WebBluetooth API, connect your Arduino to pretty much anything that runs Chrome! Click <a href="https://hewittwill.github.io/WebBluetooth-Terminal/">here</a> to check it out. See <a href="https://github.com/WebBluetoothCG/web-bluetooth/blob/master/implementation-status.md">this</a> link for full implementation details.
<br><br>
I would really appreciate everyones feedback and testing data to see where it works / with what hardware / how reliably so we can try make it a bit more consistent. 
<br><br>
<b>Setup / Wiring Guide:</b><br><br>
To use the WebBluetooth Terminal you will need an Arduino (or pretty much any other microcontroller) and a HM Bluetooth Low-Energy module, if you want to setup your own BLE module the Service UUID is <code>0000ffe0-0000-1000-8000-00805f9b34fb</code> and the Characteristic UUID is <code>0000ffe1-0000-1000-8000-00805f9b34fb</code>. Alternatively, you can fork the project and change them in the JavaScript. It's near the top (I'll make a menu to change them later).
<br>
Follow this Fritzing diagram to hookup your Arduino to one of the Bluetooth modules - pretty straightforward. Make sure to check that you're using 3.3v logic or that your BLE module is 5v logic tolerant. Admittedly, I've never bothered to use a level shifter, but it's not my fault if you let out the magic smoke by neglecting to do so.

<br>
Power it on, open the <a href="https://hewittwill.github.io/WebBluetooth-Terminal/">terminal</a> and press the green connect button. A pop-up will appear if you've correctly enabled WebBluetooth on a supported browser (Chrome now supports it natively, except on Windows where you have to navigate to this <a href"chrome://flags">link</a> and enable experimental features). Follow <a href="https://github.com/WebBluetoothCG/web-bluetooth/blob/master/implementation-status.md">this</a> link to get a list of the full implementation and how to enable it properly.
<br><br>
Click pair, and you should be auto-magically connected and have a virtual serial link between your browser and your Arduino. Load one of my example sketches and connect an LED if you want to wow your friends by letting them connect to it on THEIR phone.
<br><br>
<b>Details:</b>
<br><br>
Service UUID: <code>0000ffe0-0000-1000-8000-00805f9b34fb</code><br>
Characteristic UUID: <code>0000ffe1-0000-1000-8000-00805f9b34fb</code>
<br><br>
All the data is sent down the value of the one characteristic, 20 bytes at a time. Technically this could run into issues reading/writing to the buffer at the same time, however it probably shifts into the CC2540's memory quick enough that it's unlikely to ever be an issue. Nordic Semiconductors has a similar method that utilises two characteristics, one for RX and one for TX, but using one of their microcontrollers is waaaay overkill for a simple Bluetooth -> Serial bridge. If you want to fork it go ahead, but note that you have to host it on either a HTTPS server or locally. This is one of the security methods that the W3 guys implemented to make sure bad guys don't mess with your Bluetooth stuff.
<br>
<table>
  <tr><td><b>Platform</b></td><td><b>Implemented</b></td><td><b>Tested</b></td><td><b>Note</b></td></tr>
  <tr><td>Chrome (OSX)</td><td>&#10003;</td><td>&#10003;</td><td></td></tr>
  <tr><td>Chrome (Android)</td><td>&#10003;</td><td>&#10003;</td><td></td></tr>
  <tr><td>Chrome (Windows)</td><td>&#10003;</td><td>&#10003;</td><td>Requires experimental flag</td></tr>
  <tr><td>'WebBLE' (iOS)</td><td>&#10003;</td><td> &#215;</td><td></td></tr>
</table>
