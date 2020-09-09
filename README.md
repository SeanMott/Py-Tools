# PyGameGen
Generates a skeleton pygame application

# Command Line useage:

If no arguments are passed or the executable is ran it will just write the file next to the executable. The file will be named "PygameApp.py" <br>
<br>
<br>
One argument is treated as the file path where the file should be written, either absolute path or relative. The .py can be missed since the py will be added if it's missing. <br>
`PygameGen.exe "C:\\Dev\\appName.py`
<br>
<br>
If more arguments are defined they are treated as the person's name and lab name respectively. The lab flag can be ignored. <br>
`PygameGen.exe "C:\\Dev\\appName.py" "Student A" Lab42a` <br>

# Building
If you clone the repo it comes with Premake and a bat file for generating a Visual Studio project for Windows.