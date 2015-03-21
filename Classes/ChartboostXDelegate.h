#ifndef ChartboostX_Delegate_h
#define ChartboostX_Delegate_h

//typedef void (*call_vFunction)(const char*, const char*); // type for conciseness
//typedef bool (*call_bFunction)(const char*, const char*); // type for conciseness

class boolFunctor
{
public:
	virtual ~boolFunctor(){}
	virtual bool run(const char*, const char*) {return true;};
};

class voidFunctor
{
public:
	virtual ~voidFunctor(){}
	virtual void run(const char*, const char*) {};
};


class ChartboostXDelegate {
public:
    virtual ~ChartboostXDelegate() {}
  
    virtual void bCallBackSet(boolFunctor* bF) { callB =  bF; };
    virtual void vCallBackSet(voidFunctor* vF) { callV =  vF; };
    virtual bool bCallBack(const char* function, const char* location) 
    {
    	if(callB)
    	{
    		return callB->run(function, location);
    	}
    	else
    		return true; 
    };
    virtual void vCallBack(const char* function, const char* location)
    {
    	if(callV)
    	{
    		callV->run(function, location);
    	}
    };

private:
	boolFunctor* callB;
	voidFunctor* callV;

};

#endif // ChartboostX_ChartboostXJni_h