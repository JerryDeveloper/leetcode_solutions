Data structure:
1. a struct which stores the file tree hierarchy. inaccessible to outside world. the struct should store: isFile or not, if it's a file the content, and all children (in a dictionary, key is the name).
2. the File system should store the top node's children (a dictionary).

Operations:
ls: traverse through the first level children. return the list of names
mkdir: split the input by first '/', and create child if not exist, or find the child if exist, call child's mkdir and pass in remaining path, until there's no '/' in the path, which means it's a leaf
addContentToFile: find the file object, create one if not exist. append content to the file conent.
readContentFromFile: find the file and return the content.


beat only 17.92%. need to improve