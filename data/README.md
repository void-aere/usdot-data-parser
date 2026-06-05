This is where Form 41 Schedule T2 data files will be placed.

To update the dataset:

1.  Go to https://transtats.bts.gov/
2.  Click on "Aviation" on the sidebar
3.  Click on "Air Carrier Summary Data (Form 41 and 298C Summary Data)"
4.  Click on "T2: U.S. Air Carrier TRAFFIC And Capacity Statistics by Aircraft Type"
5.  Click on "Download" on the sidebar
6.  Select, at minimum, the following fields: `Year`, `AirHours`, `AirDaysEquip`
7.  Near the top, specify "All Years" in the "Filter Year" field
8.  Click on the "Download" button
9.  Unzip the downloaded file and replace `T_SCHEDULE_T2.csv` in this directory with its contents
10. Run the program in the parent directory to obtain updated calculations

[Here's a link straight to the download page](https://transtats.bts.gov/DL_SelectFields.aspx?gnoyr_VQ=FIH&QO_fu146_anzr=Nv4%20Pn44vr4%20f7zzn4B)
but I have no idea if it will work in the future.

Required fields for download:

-   `Year`
-   `AirHours`
-   `AirDaysEquip`

Make sure that the downloaded CSV file ends up in this directory titled
`T_SCHEDULE_T2.csv`.
