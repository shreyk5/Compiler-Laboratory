#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int main()
{
	ifstream fp0("input.xsm");
	string s;
	map<int,int>Address;
	int line = 0;

	while(getline(fp0,s))
	{
		//cout<<s<<endl;
		line++;
		//cout<<s<<endl;
		int n = s.length();
		bool store = 0;

		if(n>=5)
		{
			for(int i=0;i<n;i++)
			{
				string test = "";
				
				for(int j=i;j<n;j++)
				{
					test += s[j];
					//cout<<test<<endl;
					if(test == "LABEL" || test == "F" || test == "MAIN")
					{
							int lbl1 = 0;
							j++;
							while(j<n)
							{
								//cout<<s[j];
								if(s[j] == ':')
								{
									store = 1;
									break;
								}

								lbl1 = lbl1*10 + s[j]-'0';
								
								j++;
							}
							if(store)
							{
								if(test == "MAIN")
								{
									Address[-inf] = 2056 + (line-9)*2;
								}
								else if(test == "LABEL")
									Address[lbl1] = 2056 + (line-9)*2;
								else
								{
									Address[-lbl1] = 2056 + (line-9)*2;
								}
							}
							store = 0;
							//cout<<lbl1<<endl; 
							//cout<<Address[lbl1]<<endl;
						}
				}
			}
		}
	}

	ifstream fp1("input.xsm");
	FILE *fp = fopen("/home/shrey/xsm_expl/xsm_progs/output.xsm","w");

	while(getline(fp1,s))
	{
		line++;
		int n = s.length();
		int start = 0;
		int end = n-1;
		int add_address = 0;
		int lbl = 0;

		if(1)
		{
			for(int i=0;i<n;i++)
			{
				string test = "";
				for(int j=i;j<n;j++)
				{
					test += s[j];
					int poss = 1;
					int save_j = j;
					if(test == "LABEL" || test == "F" || test == "MAIN")
					{
						while(j<n)
						{
							//test += s[j];
							if(s[j] == ':')
							{
								poss = 0;
								start = max(start,j+2);
								//cout<<start<<endl;
								break;
							}
							j++;
						}
					}

					j = save_j;
					if((test == "LABEL" || test == "F" || test == "MAIN") && poss)
					{
						//cout<<"hi";

						add_address = 1;
						end = i-1;

						if(test == "MAIN")
						{
							lbl = -inf;
						}

						else
						{
							j++;
							while(j<n)
							{
								lbl = lbl*10 + s[j]-'0';
								j++;
							}
							if(test == "F")
								lbl = -lbl;
						}
					}	
				}
			}
		}

		//cout<<start<<" "<<end<<endl;
		for(int i = start;i<=end;i++)
		{
			fprintf(fp,"%c",s[i]);
		}

		if(add_address == 1)
		{
			fprintf(fp,"%d",Address[lbl]);
		}
		fprintf(fp,"\n");
	}


	return 0;
}