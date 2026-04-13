# Ranking List

# Idea
The Ranking List's purpose is to add name entries into a ranking with their designated placement (for example 12.Phil). The entries are saved in a .txt file and are
formatted accordingly.__
In case a collision happens, say the user inputs 166.Robin, but there is already an entry at 166 (say 166.Mike), then Robin takes Mike's place as 166.Robin. Mike
is shifted by one entry to 167.Mike. If there is also another entry at 167, Mike stays at 167 as 167.Mike, and the other entry gets shifted... and so on. (Insertion Sort Light)__
With that, new entries with placements can be added freely everywhere in the list.

# How to operate?
- Press 1 if you want to add an entry, press 0 if you want to stop adding entries
- Enter a name (it can't have numbers inside)
- Enter a placement which is smaller than 2000

# Limits
- the maximum place should be 1999

# Notes
Nowadays I would have probably approached the project differently. This code is very manual and low level, but thanks to it, it offered me an even greater
challenge to train my structural problem solving and coming up with creative solutions. I've listed some ideas in Fix.

# To Fix
- add dynamic number of possible entries
- rework the amount of strings and replace them with a strctural approach (especially one = " ", two = "  ", etc.)
- double opening and closing of file
- continous resetting of strings
- add strcuts
- too many variables
