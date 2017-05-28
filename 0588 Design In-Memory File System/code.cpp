class FileSystem {
    struct Node
    {
        bool isFile = false;
        string content = "";
        map<string, Node*> children;
    };
    Node* root;
    
    vector<string> parsePath(string path)
    {
        istringstream iss(path);
        vector<string> path_tokens;
        string token;
        
        while(getline(iss, token, '/'))
        {
            if(token.empty())
                continue;
            path_tokens.push_back(token);
            
        }
        
        return path_tokens;
    }
public:
    FileSystem() {
        root = new Node();
    }
    
    vector<string> ls(string path) {
        vector<string> path_tokens = parsePath(path);
        
        Node *target = root;
        
        for(string t : path_tokens)
        {
            target = target->children[t];
        }
        
        vector<string> output;
        if(target->isFile)
        {
            output.push_back(path_tokens[path_tokens.size() - 1]);
        }
        else
        {
            for(auto p : target->children)
            {
                output.push_back(p.first);
            }
        }
        
        return output;
    }
    
    void mkdir(string path) {
        vector<string> path_tokens = parsePath(path);
        
        Node *cur = root;
        for(string t : path_tokens)
        {
            auto ind = (cur->children).find(t);
            if(ind == (cur->children).end())
            {
                cur->children[t] = new Node();
            }    
            cur = cur->children[t];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> path_tokens = parsePath(filePath);
        
        Node *cur = root;
        for(string t : path_tokens)
        {
            auto ind = (cur->children).find(t);
            if(ind == (cur->children).end())
            {
                cur->children[t] = new Node();
            }    
            cur = cur->children[t];
        }
        
        cur->isFile = true;
        cur->content += content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> path_tokens = parsePath(filePath);
        
        // assume path is valid
        Node *cur = root;
        for(string t : path_tokens)
        {
            cur = cur->children[t];
        }
        
        return cur->content;
    }
    
    ~FileSystem()
    {
        delete root;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem obj = new FileSystem();
 * vector<string> param_1 = obj.ls(path);
 * obj.mkdir(path);
 * obj.addContentToFile(filePath,content);
 * string param_4 = obj.readContentFromFile(filePath);
 */