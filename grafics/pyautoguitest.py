import pyautogui as gui

tick = 0
gui.keyDown('shift')
while (0 == 0):
    gui.click(clicks=1, interval=0.1)
    tick += 1
    if (tick == 40):
        tick = 0
        gui.press('1')
        gui.press('2')
        gui.press('3')
