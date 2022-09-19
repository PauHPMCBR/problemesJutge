from pynput import mouse

keyboard = Controller()

keyboard.press(Key.shift)

while(keyboard.pressed(Key.control)):
    keyboard.click
