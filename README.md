# pipex (42 project)
## Overview
This project is the discovery in detail and by programming of a UNIX mechanism that you already know.
## Manadotory part
This part aims to copy behavior of next shell command: \
`< infile cmd1 | cmd2 > outfile`, where infile and outfile are files to read from and to write to, \
cmd1 and cmd2 are shell commands to execute.
### Running
To compile this part you have to run `make`, firstly. \
Then run `./pipex infile cmd1 cmd2 outfile` to lauch the program
## Bonus part
This part aims to copy behavior of next shell commands:
1. `<infile cmd1 | cmd2 | cmd3 | ... | cmdn > outfile`, where infile and outfile are files to read from and to write to, \
cmd1, cmd2, ..., cmdn are shell commands to execute.
2. `cmd << LIMITER | cmd1 > outfile`, where outfile is file to write to, \
cmd and cmd1 are shell commands to execute and LIMITER is stop word for heredoc input.
### Running
To compile this part you have to run `make bonus`, firstly. \
Then run `./pipex infile cmd1 cmd2 ... cmdn outfile` to lauch the program without heredoc. \
Or run `./pipex here_doc LIMITER cmd cmd1 outfile` to lauch the program with heredoc.
