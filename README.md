# Anatomy Fitness
*Anatomy Fitness* is a CS group project submitted as a Finals project to Programming I university course.
The objective is to create an 3D model app that provides highlights different muscle groups and provide 
a list of exercises that are most effective at training those regions.
## Dependencies
The following project was created for a Windows 11 environment. There is no guarantee this will work OSX environment or other any Linux distro.<br>
To properly clone the project ensure you are using:
- Unreal Engine version 5.5.0
- Visual Studio 2022 version 17

## Compilation
The following should ensure a successful compilation of the project:
1. Clone the repo
2. Right-click on the `.uproject` file and click `Generate Visual Studio Project Files`
3. Copy a `Binaries/` directory from another (or blank) UE5 project to this project's directory
4. Open Visual Studio and click `Build Solution`
	- Ensure the top bar is set to `DebugGame Editor`/`Development Editor` and `Win64`
	- Right-click `Project` and click `Set as Startup Project`

This ensures the `.uproject` file will work properly on your Windows machine and be an up-to-date version of the project.