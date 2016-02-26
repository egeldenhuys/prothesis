Requirements
============

This document will list the required features of the Prothesis Program.

- Cross Platform
- GUI
- Features from original program
- Save and Load user data
- Notify user of data saved state
- Ability to update form internet
- Tested on wide range of computers
- Alert the user if the data cannot be saved

# Requirements Breakdown
## Cross platform
- Will be written in **C++** as it can be more easily executed on different operating systems
- GUI will be created using Qt as it it cross platform
- Should support Windows, Linux Mint, Mac
- Should use native libraries. I.e. not require the user to install additional libraries

## Data Storage 
- Data will be stored in a file in the current directory. The application will be deployed on a USB so this will be the most practical way.
- Plain text to allow easier debugging.
- If the USB becomes unavailable it will notify the user to put it back in or save to the roaming folder, or a folder of their choice.
- File can be backed up by the user (we will teach them this file is important!)
- File can be easily viewed without the program
- File can be transferred to another USB.

## Development Approach

- Define - What needs to be achieved/solved.
- Plan - How will it be done
- Build - Implement the created solution
- Test - Test the solution and fix bugs
- Review - Can it be improved?

## Save and Load data
- Will check the data being loaded for errors

## Target Audience
- Will be mostly people between the ages of 18+
- Will not have a technical background
- Will not backup user data by themselves
- Will not have experience debugging an application
- Will want a simple interface
- Want many tool tips and online help
- Visual guidance
- Will not have a lot of free time
- Want no errors
