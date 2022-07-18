#ifndef CONNECTION_H
#define CONNECTION_H

class Connection 
{
private:
    const char *server,*user,*password,*database;
public:
    Connection(){}

    Connection(const char* s,const char* u, const char* p, const char*d)
    {
        this->server = s;
        this->user = u;
        this->password = p;
        this->database = d;
    }

    ~Connection(){}
    
    //get functions
    
    const char *getServer()
    {
        return this->server;
    }
    const char *getUser()
    {
        return this->user;
    }
    const char *getPassword()
    {
        return this->password;
    }
    const char *getDatabase()
    {
        return this->database;
    }
    
    //set functions
    
    void setServer(char* s)
    {
    	this->server = s;
    }
    
    void setUser(char *s)
    {
    	this->user = user;
    }
    
    void setPassword(char *p)
    {
    	this->password = p;
    }
    
    void setDatabase(char* d)
    {
    	this->database = d;
    }
};

#endif
