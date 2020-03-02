# meguminit

An init "system" whsoe only purpose is to launch `cat` to print a file, and hand execution over to `/bin/init`.
Expect to see a Megumin linger for around two seconds after kernel boot and before system init.
https://github.com/JuhaJGamer/meguminit.git
## Installation

1. Clone this repository

2. Create a `build` directory (`mkdir build`)

3. Prepare the build with `cmake ..`

4. Build with `make`

5. Install the files with `(sudo) make install`

6. Set your boot loader options so that linux loads with the init kernel parameter set as `init=/bin/meguminit`

7. Reboot

## Configuration

The file that is printed is located at `/etc/meg.txt`. Change the file to change the output.
The two-second delay might become annoying as it slows down boot time. To disable it, comment out the `sleep(2);` line in `main.cc` before building.

## License

Do whatever the fuck you want, I don't think you'll make huge sums of money with an init wrapper.
