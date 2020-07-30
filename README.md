# Airspacer

Convert Airspace files from [Soaring Web](http://soaringweb.org/Airspace) to X-Plane 11 compatible files

## Usage

`airspacer <input_file> <output_file>`

## Example

`airspacer France_20-05.txt FR.txt`

and put FR.txt in ~/X-Plane 11/Custom Data/airspaces folder

## Install
```bash
mkdir build
cd build
cmake ..
make
sudo make install
```

## Airspaces
in airspace-xp11 folder
| Files         | Country           | Remarks            |
| ------------- |-------------------| -------------------|
| EB_WE.txt     | Belgium (Weekend) | corrected manually |
| EB_WK.txt     | Belgium (Week)    | almost corr. manu. |
| LF.txt        | France            | not validated      |
| EH.txt        | Nederlands        | not validated      |
| ED.txt        | Germany           | not validated      |
| LE.txt        | Spain             | not checked        |
| LI.txt        | Italy             | not checked        |




## Garmin 1000 in X-Plane 11

![airspace scree shot](images/airspace_ED.png)
