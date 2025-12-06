# DTMF Coding and Decoding System in MATLAB

**Brief Description:** Development of a software system in MATLAB for the generation and detection of DTMF (Dual-Tone Multi-Frequency) signals.
This project implements an encoder that generates audio signals corresponding to telephone digits (0-9) and a decoder based on a bank of Kaiser window FIR filters to identify the frequencies present and reconstruct the dialed number.
- [Youtube Presentation DTMF PT1](LINK_TO_YOUR_VIDEO_HERE)
- [Youtube Presentation DTMF PT2](LINK_TO_YOUR_VIDEO_HERE)

---

## Table of Contents

1. [Installation](#installation)
2. [Usage](#usage)
3. [Common Issues](#common-issues)
4. [Documentation](#documentation)
5. [References](#references)
6. [Contribution](#contribution)
7. [License](#license)
8. [Authors](#authors)
9. [Acknowledgments](#acknowledgments)

---

## Installation
Below is a written guide on how to prepare the MATLAB environment for running the simulation and digital signal processing scripts.

**Prerequisites:**
- PC running Windows, Linux, or MacOS.
- Required Software:
  - [MATLAB](https://www.mathworks.com/products/matlab.html) (Version R2016a or higher recommended).
  - [Signal Processing Toolbox](https://www.mathworks.com/products/signal.html) (Essential for `fir1` and `kaiserord` functions).

**Installation Steps:**
1. Clone the repository or download the files:
   ```bash
   git clone [https://github.com/FacundoCostarelli/TU_REPO_DTMF](https://github.com/FacundoCostarelli/TU_REPO_DTMF)


2. Configure the MATLAB environment:
    - Open MATLAB.
    - Navigate to the folder where the .m files were downloaded (all files must be in the same directory: tp2.m, rowX.m, colX.m, make_signal_dtmf.m, etc.).
    - Right-click on the folder in the MATLAB file browser and select "Add to Path" > "Selected Folders". This ensures MATLAB can locate the filter functions and auxiliary scripts.

---

## Usage
Once the files are downloaded and the path is configured, you can test the complete system using the main test script.

**Usage Steps:**
- Open the tp2.m file in the MATLAB editor.
- Click the Play/Run button to run the project or press F5. You must strictly run it from the "tp2.m" file.

**Script Features**
- The script automatically performs the following:
- Defines a sampling frequency (fs = 8000 Hz).
- Iterates through digits 0 to 9.
- Encoding: Calls make_signal_dtmf to generate the audio by summing the cosines of the corresponding frequencies.
- Playback: Plays the generated sound (ensure your volume is on).
- Decoding: Calls get_number_from_dtmf. This function passes the signal through a bank of 7 band-pass filters (designed with a Kaiser window) and determines which key was pressed based on the input/output energy ratio.
- Displays the detected result in the Command Window.

**Main Functions**
- make_signal_dtmf(n, fs, d): Generates the temporal DTMF signal.
- get_number_from_dtmf(x, fs): Detects the digit by analyzing energy after filtering the signal.
- rowX(fs) and colX(fs): Functions that generate the specific FIR filter objects for each standard DTMF frequency.

---

## Common Issues
1. Filter Design Error (NaNs):
  - Description: When running, the error "NaN's cannot be converted to logicals" appears in kaiserord.
  - Solution: This is usually caused by a typo in the frequency vectors. Check the file row4.m. Ensure the frequency vector is [Fstop1 Fpass1 Fpass2 Fstop2] and that Fpass2 is not repeated at the end.
2. Detected Digit Mismatch:
  - Description: The system detects the wrong number or returns 0.
  - Solution: Check the energy threshold in get_number_from_dtmf.m. It is currently set to Ey/Ex >= 0.45. If the signal is very noisy, this threshold may need adjustment.
3. Audio not heard or cut off:
  - Description: The playblocking function fails, or the audio is too brief.
  - Solution: Verify that the variable d (duration) in tp2.m is sufficient (e.g., 2 seconds) and that the sampling frequency fs is compatible with your audio card (8000 Hz is standard).

---

## Documentation
For further information and details on the standards and methods used:

- [ITU-T Recommendation Q.23 - Technical specifications for DTMF frequencies.](https://www.itu.int/rec/T-REC-Q.23/en).
- [FIR Filter Design in MATLAB - Documentation on fir1.](https://www.mathworks.com/help/signal/ug/fir-filter-design.html).
- [Kaiser Window - Details on parameter estimation for Kaiser window filters.](https://www.mathworks.com/help/signal/ref/kaiserord.html).

---

## References
- Official MathWorks Documentation (MATLAB).
- Class notes from the Signals Analysis and Signal Processing Systems Chair.
- [StackOverflow Forums - Queries regarding MATLAB syntax errors.](https://stackoverflow.com/questions).

---

## Contribution
All collaboration is welcome. Follow these steps to contribute:

  1. Fork the repository.
  2. Create a new branch for your improvement (e.g., filter optimization or GUI):
     - git checkout -b feature/new-improvement
  3. Make your changes and commit:
     - git commit -m "Improvement in energy detection"
  4. Push to your branch:
     - git push origin feature/new-improvement
  5. Create a Pull Request describing your changes.

---

## License
This project is licensed under the GNU General Public License v3.0. You may use, modify, and distribute this project while respecting the terms of the license.

## Authors
- Facundo Costarelli

---

## Acknowledgments
- Digital Signal Processing Chair - National Technological University (UTN BA).

---

## Abbreviations:
- DTMF --> Dual-Tone Multi-Frequency.
- FIR --> Finite Impulse Response.
- FS --> Sampling Frequency.
