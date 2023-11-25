CPPFileID = fopen('TestFile.cpp', 'w');

if CPPFileID == -1
    error('Could not open file for writing');
end

FileContents = [];
% make file contents 







fprintf(CPPFileID, '%s\n', FileContents);

% Close the file
fclose(CPPFileID);