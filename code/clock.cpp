#include<bits/stdc++.h>
using namespace std; 
#ifndef TOOL_H
#ifndef EXT_H
#define TOOL_H
namespace hdk{
	namespace tool{
		template<typename T>
		T floor_sqrt(T x,T l=1,T r=-1){
			if(r==-1) r=x;
			int ans=-1;
			while(l<=r){
				int mid=(l+r)/2;
				if(mid*mid<=x){
					l=mid+1;
					ans=mid;
				}
				else{
					r=mid-1;
				}
			}
			return ans;
		}
		template<typename T>
		void print(T x,bool first=true){
			if(x<0){
				putchar('-');
				print(-x,false);
				return;
			}
			if(x==0){
				if(first) putchar('0');
				return;
			}
			print(x/10,false);
			putchar((int)(x%10)+'0');
		}
		template<typename T>
		std::string to_string(T x){
			std::string res;bool f=false;
			if(x<0){
				f=true;
				x*=-1;
			}
			while(x){
				res.push_back((int)(x%10)+'0');
				x/=10;
			}
			reverse(res.begin(),res.end());
			if(f) res.push_back('-');
			if(res.empty()) res.push_back('0');
			return res;
		}
		long long to_number(std::string x){
			long long res=0;bool f=false;
			for(int i=0;i<=(int)x.length()-1;++i){
				if(x[i]=='-'){
					f=true;
				}
				else{
					res=res*10+x[i]-'0';
				}
			}
			return res*(f?-1:1);
		}
		template<typename T>
		std::string to_bit(T x){
			std::string ans;
			while(x){
				ans.push_back((x&1)+'0');
				x>>=1;
			}
			std::reverse(ans.begin(),ans.end());
			return ans;
		}
		std::string fixed_size(std::string x,int size,char fillchar='0'){
			std::string ans=x;
			std::reverse(ans.begin(),ans.end());
			while((int)ans.size()!=size) ans.push_back(fillchar);
			std::reverse(ans.begin(),ans.end());
			return ans;
		}
		bool copyfile(const char*in,const char *out){
			ifstream _fin(in);
			if(!_fin){
				cout<<"Error: File '"<<in<<"' not found"<<endl;
				return 0;
			}
			ofstream _fout(out);
			if(!_fout){
				cout<<"Error: File '"<<out<<"' not found"<<endl;
				return 0;
			}
			while(!_fin.eof()){
				char _a[1000001];_fin.getline(_a,1000000);
				_fout<<_a<<"\n";
			}
			return 1;
		}
		bool printfile(const char*in){
			ifstream _fin(in);
			if(!_fin){
				cout<<"Error: File '"<<in<<"' not found"<<endl;
				return 0;
			}
			cout<<"File '"<<in<<"'"<<endl;
			while(!_fin.eof()){
				char _a[1000001];_fin.getline(_a,1000000);
				cout<<_a<<"\n";
			}
			return 1;
		}
		bool fc(const char *file_A,const char *file_B,bool display=false,bool debug_mode=false){
			std::string a,b;
			if(display){printf("fc %s and %s\n",file_A,file_B);}
			bool eofA=false,eofB=false;std::ifstream f1,f2;f1.open(file_A);f2.open(file_B);
			if(!f1){
				cout<<"File '"<<file_A<<"' not found"<<endl;
				return true;
			}
			if(!f2){
				cout<<"File '"<<file_B<<"' not found"<<endl;
				return true;
			}
			while(1){
				if(f1.eof()){eofA=true;}
				else{f1>>a;}
				if(f2.eof()){eofB=true;}
				if(eofA and eofB){if(display) printf("File is equal.\n"); return false;}
				else if(eofA or eofB){if(display) printf("Length is not equal.\n");return true;}
				else{f2>>b;}
				if(debug_mode){printf("Compare: '%s' '%s'\n",a.c_str(),b.c_str());}
				if(a!=b){if(display){
				printf("Find Difference: \n");
				printf("%s: %s\n",file_A,a.c_str());
				printf("%s: %s\n",file_B,b.c_str());}
				return true;
				}
			}
		}
		bool fc(const std::string file_A,const std::string file_B,bool display=false,bool debug_mode=false){
			return fc(file_A.c_str(),file_B.c_str(),display,debug_mode);
		}
		const long long clocks_per_sec=CLOCKS_PER_SEC;
		#define time_s *clocks_per_sec
		#define time_ms *clocks_per_sec/1000.0
		class _time{
			private:
				long long last_clocks=-1;
				long long start_clocks=0;
			public:
				inline void sleep(long long clocks){
					int st=clock();
					while(clock()-st<=clocks);
				}
				inline long long record_time(){
					if(last_clocks==-1){
						last_clocks=clock();
						return 0;
					}
					else{
						int res=clock()-last_clocks;
						last_clocks=-1;
						return res;
					}
				}
				inline long long record_time(bool is_start){
					if(is_start){
						start_clocks=clock();
						return start_clocks;
					}
					else{
						return clock()-start_clocks;
					}
				}
		};
		string file_name(const string file){
			int pos=(int)file.length()-1;
			for(int i=(int)file.length()-1;i>=0;--i){
				if(file[i]=='.'){
					pos=i-1;break;
				}
			}
			string ans;
			for(int i=0;i<=pos;++i){
				ans.push_back(file[i]);
			}
			return ans;
		}
		int system(const string x){
			return std::system(x.c_str());
		}
		class bad_expression{};
		inline const pair<int,int> get_numeraic(const string &x,int start_pos){
			int res=0,f=1;
			for(int i=start_pos;i<=(int)x.length()-1;++i){
				if(x[i]=='-'){
					if(i==start_pos) f=-1;
					else throw bad_expression();
				}
				else if(x[i]==':'){
					return {res*f,i+1};
				}
				else if(isdigit(x[i])) res=res*10+x[i]-'0';
			}
			return {res*f,(int)x.length()};
		}
		inline const string substr(const string &x,int opt0=0,int opt1=0,int opt2=0){
			string ret="";
			if(opt0<0){
				opt0=(int)x.length()+opt0;
				if(opt0<0) throw bad_expression();
			}
			if(opt1<0){
				opt1=(int)x.length()+opt1;
				if(opt1<0) throw bad_expression();
			}
			if(opt2==0){
				for(int i=opt0;i<((opt1==0)?(int)x.length():opt1);++i){
					ret.push_back(x[i]);
				}
			}
			else if(opt2>0){
				for(int i=opt0;i<((opt1==0)?(int)x.length():opt1);i+=opt2){
					ret.push_back(x[i]);
				}
			}
			else{
				for(int i=((opt1==0)?(int)x.length():opt1)-1;i>=opt0;i+=opt2){
					ret.push_back(x[i]);
				}
			}
			return ret;
		}
		inline const string substr(const string &x,string expr=""){
			if(expr.empty()) return x;
			for(char&i:expr) if(i=='.' or i==';' or i==',' or i=='/' or i==' ') i=':';
			for(char i:expr) if(i!='-' and i!=':' and !isdigit(i)) throw bad_expression();
			vector<int>opt;
			int pos=0;
			while(pos<(int)expr.length()){
				if(expr[pos]==':'){
					opt.push_back(0);
					pos++;
				}
				else{
					auto rt=get_numeraic(expr,pos);
					opt.push_back(rt.first);
					pos=rt.second;
				}
			}
			if(expr.back()==':') opt.push_back(0);
			if(opt.size()>3ul) throw bad_expression();
			string ret="";
			if(opt[0]<0){
				opt[0]=(int)x.length()+opt[0];
				if(opt[0]<0) throw bad_expression();
			}
			if(opt[1]<0){
				opt[1]=(int)x.length()+opt[1];
				if(opt[1]<0) throw bad_expression();
			}
			if(opt.size()==1ul){
				for(int i=opt[0];i<(int)x.length();++i){
					ret.push_back(x[i]);
				}
				return ret;
			}
			if(opt.size()==2ul){
				for(int i=opt[0];i<((opt[1]==0)?(int)x.length():opt[1]);++i){
					ret.push_back(x[i]);
				}
				return ret;
			}
			if(opt.size()==3ul){
				if(opt[2]==0){
					for(int i=opt[0];i<((opt[1]==0)?(int)x.length():opt[1]);++i){
						ret.push_back(x[i]);
					}
				}
				else if(opt[2]>0){
					for(int i=opt[0];i<((opt[1]==0)?(int)x.length():opt[1]);i+=opt[2]){
						ret.push_back(x[i]);
					}
				}
				else{
					for(int i=((opt[1]==0)?(int)x.length():opt[1])-1;i>=opt[0];i+=opt[2]){
						ret.push_back(x[i]);
					}
				}
				return ret;
			}
			throw bad_expression();
			return "";
		}
		inline const string substr(const string &x,int start_pos,int length){
			return x.substr(start_pos,length);
		}
		class str_t{
			private:string str;
			public:str_t(const string &x){str=x;}
			inline const string operator[](string x){return substr(str,x);}
			inline const string operator[](const vector<int>&opt){return substr(str,opt[1],opt[2],opt[3]);}
			inline const string operator()(int opt1,int opt2,int opt3){return substr(str,opt1,opt2,opt3);}
			inline const string operator()(string x){return substr(str,x);}
			inline const string operator()(const vector<int>&opt){return substr(str,opt[1],opt[2],opt[3]);}
		};
		const string lowercase(const string&x){
			string res;
			for(char i:x){
				if(i>='A' and i<='Z') res.push_back(i-'A'+'a');
				else res.push_back(i);
			}
			return res;
		}
		const string uppercase(const string&x){
			string res;
			for(char i:x){
				if(i>='a' and i<='z') res.push_back(i-'a'+'A');
				else res.push_back(i);
			}
			return res;
		}
		template<typename return_value_type=unsigned long long,return_value_type numer=233,return_value_type mod=0>
		class string_hash{
			private:return_value_type get_hash(const string &x){
				return_value_type res=0;
				for(char i:x){
					if(mod==0) res=res*numer+i;
					else res=(1ll*res*numer%mod+i)%mod;
				}
				return res;
			}
			public:return_value_type operator()(const string &x){return get_hash(x);}
			return_value_type operator[](const string &x){return get_hash(x);}
		};
		string_hash<> strhash;
	}
}
#endif
#endif
#ifndef TIMES_H
#define TIMES_H
using namespace hdk::tool;
namespace hdk{
    char target_output[10001];
    struct times{
        typedef const std::string times_t;
        typedef const std::string format_t;
        times_t get_format(format_t x){
            time_t t=std::time(0);
            strftime(target_output,sizeof(target_output),x.c_str(),localtime(&t));
            return target_output;
        }
        times_t short_weekname(){return get_format("%a");}
        times_t weekname(){return get_format("%A");}
        times_t short_monthname(){return get_format("%b");}
        times_t monthname(){return get_format("%B");}
        times_t date_and_time(){return get_format("%c");}
        times_t date_of_month(){return get_format("%d");}
        times_t hours_24(){return get_format("%H");}
        times_t hours_12(){return get_format("%I");}
        times_t date_of_year(){return get_format("%j");}
        times_t month(){return get_format("%m");}
        times_t minute(){return get_format("%M");}
        times_t times_12(){return get_format("%p");}
        times_t second(){return get_format("%S");}
        times_t date_of_week(){return get_format("%w");}
        times_t week_of_year(){return get_format("%W");}
        times_t week_of_year_start_from_sunday(){return get_format("%U");}
        times_t date(){return get_format("%x");}
        times_t time(){return get_format("%X");}
        times_t short_year(){return get_format("%y");}
        times_t year(){return get_format("%Y");}
        times_t short_time_zone(){return get_format("%z");}
        times_t time_zone(){return get_format("%Z");}
    };
    struct hm_times_t{
        int hours,minute;
        hm_times_t(){}
        hm_times_t(int _h,int _m){hours=_h;minute=_m;}
        hm_times_t(const pair<int,int>hm){hours=hm.first;minute=hm.second;}
        hm_times_t(int _h){hours=_h;minute=0;}
    };
    int hours(long double x){
        return 60*x;
    }
    struct times_table{
        struct time_area{
            string name;
            hm_times_t start;
            hm_times_t end;
            time_area(const string a,const hm_times_t b,const hm_times_t c){
                name=a;
                start=b;
                end=c;
            }
            time_area(const string a,int b,int c,int d,int e){
                name=a;
                start=hm_times_t(b,c);
                end=hm_times_t(d,e);
            }
            bool in(const hm_times_t x){
                if(x.hours==start.hours and x.hours==end.hours){
                    return x.minute>=start.minute and x.minute<end.minute;
                }
                if(x.hours==start.hours){
                    return x.minute>=start.minute;
                }
                if(x.hours==end.hours){
                    return x.minute<end.minute;
                }
                return x.hours>start.hours and x.hours<end.hours;
            }
        };
        vector<time_area>v;
        times_table(const vector<time_area>&x){
            v=x;
        }
        const string operator[](const hm_times_t x){
            for(time_area i:v){
                if(i.in(x)){
                    return (string)"'"+i.name+"' ["+to_string(i.start.hours)+":"+fixed_size(to_string(i.start.minute),2,'0')+"-"+to_string(i.end.hours)+":"+fixed_size(to_string(i.end.minute),2,'0')+"]";
                }
            }
            return "No activity";
        }
    };
    int continued_time(const hm_times_t &a,const hm_times_t &b){
        return b.hours*60+b.minute-a.hours*60-a.minute;
    }
    struct ex_times_table{        
        struct ex_time_area{
            string name;
            hm_times_t start;
            hm_times_t end;
            int last_times;
            ex_time_area(const string a,const hm_times_t b,const hm_times_t c,int ls){
                name=a;
                start=b;
                end=c;
                last_times=ls;
            }
            ex_time_area(const string a,int b,int c,int d,int e,int ls){
                name=a;
                start=hm_times_t(b,c);
                end=hm_times_t(d,e);
                last_times=ls;
            }
            ex_time_area(const string a,const hm_times_t b,const hm_times_t c){
                name=a;
                start=b;
                end=c;
                last_times=continued_time(start,end);
            }
            ex_time_area(const string a,int b,int c,int d,int e){
                name=a;
                start=hm_times_t(b,c);
                end=hm_times_t(d,e);
                last_times=continued_time(start,end);
            }
            bool in(const hm_times_t x){
                if(x.hours==start.hours and x.hours==end.hours){
                    return x.minute>=start.minute and x.minute<end.minute;
                }
                if(x.hours==start.hours){
                    return x.minute>=start.minute;
                }
                if(x.hours==end.hours){
                    return x.minute<end.minute;
                }
                return x.hours>start.hours and x.hours<end.hours;
            }
        };
        vector<ex_time_area>v;
        ex_times_table(const vector<ex_time_area>&x){
            v=x;
        }
        pair<const string,pair<hm_times_t,int>> operator[](const hm_times_t x){
            for(ex_time_area i:v){
                if(i.in(x)){
                    return {(string)"'"+i.name+"' ["+to_string(i.start.hours)+":"+fixed_size(to_string(i.start.minute),2,'0')+"-"+to_string(i.end.hours)+":"+fixed_size(to_string(i.end.minute),2,'0')+"]",{i.start,i.last_times}};
                }
            }
            return {"No activity",{{0,0},0}};
        }
    };
}
#endif
#ifndef COLORLINUX_H
#if INT_MAX==RAND_MAX
#define COLORLINUX_H
class color{
    public:

    const string NONE=                 "\e[0m";
    const string BLACK=                "\e[0;30m";
    const string L_BLACK=              "\e[1;30m";
    const string RED=                  "\e[0;31m";
    const string L_RED=                "\e[1;31m";
    const string GREEN=                "\e[0;32m";
    const string L_GREEN=              "\e[1;32m";
    const string BROWN=                "\e[0;33m";
    const string YELLOW=               "\e[1;33m";
    const string BLUE=                 "\e[0;34m";
    const string L_BLUE=               "\e[1;34m";
    const string PURPLE=               "\e[0;35m";
    const string L_PURPLE=             "\e[1;35m";
    const string CYAN=                 "\e[0;36m";
    const string L_CYAN=               "\e[1;36m";
    const string GRAY=                 "\e[0;37m";
    const string WHITE=                "\e[1;37m";

    const string BOLD=                 "\e[1m";
    const string UNDERLINE=            "\e[4m";
    const string BLINK=                "\e[5m";
    const string REVERSE=              "\e[7m";
    const string HIDE=                 "\e[8m";
    const string CLEAR=                "\e[2J";
}color;
class color_t{
    private:string x;
    public:
    color_t operator =(const std::string y){x=y;return *this;};
    color_t(const std::string y){x=y;}
    color_t operator +(const color_t&A)const{
        color_t ans=*this;ans.x=ans.x+";"+A.x;
        return ans;
    }
    const std::string operator()()const{return x;}
};
class __const_color_t{
    private:string x;
    public:
    __const_color_t operator =(const string y){x=y;return *this;};
    __const_color_t(const string y){x=y;}
    const string operator()()const{return x;}
};
class __color{
    public:
    const __const_color_t START=(string)"\e[";
    const __const_color_t NONE=(string)"\e[0m";

    const color_t EMPTY=(string)"";
    
    const color_t HIGHLIGHT=(string)"1";
    const color_t VAGUE=(string)"2";
    const color_t ITALIC=(string)"3";
    const color_t UNDERLINE=(string)"4";
    const color_t TWINKLE=(string)"5";
    const color_t FAST_TWINKLE=(string)"6";
    const color_t REVERSE_COLOR=(string)"7";
    const color_t HIDE=(string)"8";

    struct{
        const color_t BLACK=(string)"30";
        const color_t RED=(string)"31";
        const color_t GREEN=(string)"32";
        const color_t YELLOW=(string)"33";
        const color_t BLUE=(string)"34";
        const color_t PERPLE=(string)"35";
        const color_t CRAY=(string)"36";
        const color_t WHITE=(string)"37";
    }FRONTCOLOR;

    struct{
        const color_t BLACK=(string)"40";
        const color_t RED=(string)"41";
        const color_t GREEN=(string)"42";
        const color_t YELLOW=(string)"43";
        const color_t BLUE=(string)"44";
        const color_t PERPLE=(string)"45";
        const color_t CRAY=(string)"46";
        const color_t WHITE=(string)"47";
    }BACKGROUND;
};
typedef __color __color_t;
__color_t __color_info;
#define color_print(x) printf("%s",((string)""+(x)+color.NONE).c_str())
#define printc(x,info) printf("%s",(__color_info.START()+(x)()+"m"+info+__color_info.NONE()).c_str())
#endif
#endif
#ifndef LINUX_HPP
#define LINUX_HPP
#if INT_MAX==RAND_MAX
bool linux_copyfile(const char*in,const char *out){
    ifstream _fin(in);
    if(!_fin){
        printc(__color_info.FRONTCOLOR.RED+__color_info.HIGHLIGHT,"Error");
        cout<<": File ";
        printc(__color_info.FRONTCOLOR.CRAY+__color_info.ITALIC,in);
        cout<<" not found"<<endl;
        return 0;
    }
    ofstream _fout(out);
    if(!_fout){
        printc(__color_info.FRONTCOLOR.RED+__color_info.HIGHLIGHT,"Error");
        cout<<": File ";
        printc(__color_info.FRONTCOLOR.CRAY+__color_info.ITALIC,out);
        cout<<" not found"<<endl;
        return 0;
    }
    while(!_fin.eof()){
        char _a[1000001];_fin.getline(_a,1000000);
        _fout<<_a<<"\n";
    }
    return 1;
}
bool linux_printfile(const char*in){
    ifstream _fin(in);
    if(!_fin){
        printc(__color_info.FRONTCOLOR.RED+__color_info.HIGHLIGHT,"Error");
        cout<<": File ";
        printc(__color_info.FRONTCOLOR.CRAY+__color_info.ITALIC,in);
        cout<<" not found"<<endl;
        return 0;
    }
    cout<<"File ";
    printc(__color_info.FRONTCOLOR.CRAY+__color_info.UNDERLINE+__color_info.ITALIC,in);
    cout<<endl;
    while(!_fin.eof()){
        char _a[1000001];_fin.getline(_a,1000000);
        cout<<_a<<"\n";
    }
    return 1;
}
bool linux_fc(const char *file_A,const char *file_B,bool display=true,bool debug_mode=false){
    std::string a,b;
    if(display){
        printc(__color_info.FRONTCOLOR.PERPLE,"fc");
        cout<<' ';
        printc(__color_info.FRONTCOLOR.CRAY+__color_info.UNDERLINE+__color_info.ITALIC,file_A);
        cout<<" and ";
        printc(__color_info.FRONTCOLOR.CRAY+__color_info.UNDERLINE+__color_info.ITALIC,file_B);
        cout<<endl;
    }
    bool eofA=false,eofB=false;std::ifstream f1,f2;f1.open(file_A);f2.open(file_B);
    if(!f1){
        printc(__color_info.FRONTCOLOR.RED+__color_info.HIGHLIGHT,"Error");
        cout<<": File ";
        printc(__color_info.FRONTCOLOR.CRAY+__color_info.ITALIC,file_A);
        cout<<" not found"<<endl;
        return true;
    }
    if(!f2){
        printc(__color_info.FRONTCOLOR.RED+__color_info.HIGHLIGHT,"Error");
        cout<<": File ";
        printc(__color_info.FRONTCOLOR.CRAY+__color_info.ITALIC,file_B);
        cout<<" not found"<<endl;
        return true;
    }
    while(1){
        if(f1.eof()){eofA=true;}
        else{f1>>a;}
        if(f2.eof()){eofB=true;}
        else{f2>>b;}
        if(eofA and eofB){
            if(display){
                printc(__color_info.FRONTCOLOR.GREEN+__color_info.HIGHLIGHT,"Accept");
                cout<<": File is equal.";
                cout<<endl;
                return false;
            }
        }
        else if(eofA or eofB){
            if((eofA and (b[0]=='\n' or b[0]==' ' or b[0]==0)) or (eofB and (a[0]=='\n' or a[0]==' ' or a[0]==0))){
                if(display){
                    printc(__color_info.FRONTCOLOR.GREEN+__color_info.HIGHLIGHT,"Accept");
                    cout<<": File is equal.";
                    cout<<endl;
                }
                return false;
            }
            if(display){
                printc(__color_info.FRONTCOLOR.RED+__color_info.HIGHLIGHT,"Find Difference");
                printf(" Length is not equal.\n");
                return true;
            }
        }
        if(debug_mode){
            printc(__color_info.FRONTCOLOR.PERPLE,"Compare");
            printf(": '%s' '%s'\n",a.c_str(),b.c_str());
        }
        if(a!=b){
            if(display){
                printc(__color_info.FRONTCOLOR.RED+__color_info.HIGHLIGHT,"Find Difference");
                cout<<endl;
                printc(__color_info.FRONTCOLOR.CRAY+__color_info.UNDERLINE+__color_info.ITALIC,file_A);
                printf(": %s\n",a.c_str());
                printc(__color_info.FRONTCOLOR.CRAY+__color_info.UNDERLINE+__color_info.ITALIC,file_B);
                printf(": %s\n",b.c_str());
            }
            return true;
        }
    }
}
bool linux_fc(const std::string file_A,const std::string file_B,bool display=true,bool debug_mode=false){
    return linux_fc(file_A.c_str(),file_B.c_str(),display,debug_mode);
}
void scroll_line(int size,double nowpercent,const color_t finished_color,const color_t unfinished_color){
    int finished=size*nowpercent;
    for(int i=1;i<=finished;++i){
        printc(finished_color,' ');
    }
    for(int i=finished+1;i<=size;++i){
        printc(unfinished_color,' ');
    }
}
#endif
#endif
using namespace hdk;

/*
//----- SETTING -----
*/
    const int flush_time=1;
        //屏幕刷新频率(秒)
    const bool show_nowtime=true;
        //显示当前时间
    const bool show_remain_times_line=true;
        //是否显示最后一行
    const bool show_scl=true;
        //是否显示进度条
    const bool show_percent=true;
        //是否显示当前百分比
    const bool show_remain_times=true;
        //是否显示剩余时间
    const int scl_size=20;
        //进度条大小(字符)
    const color_t scl_color=__color_info.BACKGROUND.GREEN;
        //进度条颜色
    const color_t scl_color2=__color_info.BACKGROUND.WHITE;
        //进度条(未到达区域)颜色 //关于 color_t 的生成方式详见 https://www.cnblogs.com/HaneDaCafe/p/18467949
    const times::format_t time_format="default";
        //时间显示格式
    ex_times_table day(
        {
            {"晚休",      0, 0,  6, 0},
            {"早操",      6, 0,  6,15},
            {"早读",      6,15,  6,50},
            {"早饭",      6,50,  7,20},
            {"上午第一节", 7,20,  8,20},
            {"讨论",      8,20,  8,40},
            {"上午第二节", 8,40,  9,40},
            {"讨论",      9,40, 10, 0},
            {"上午第三节",10, 0, 11, 0},
            {"讨论",     11, 0, 11,20},
            {"上午第四节",11,20, 12,10},
            {"午休",     12,10, 14, 0},
            {"下午第一节",14, 0, 14,50},
            {"讨论",     14,50, 15,10},
            {"下午第二节",15,10, 16,10},
            {"讨论",     16,10, 16,30},
            {"下午第三节",16,30, 17,30},
            {"讨论",     17,30, 17,50},
            {"下午第四节",17,50, 18,10},
            {"晚饭",     18,10, 18,35},
            {"讨论",     18,35, 18,55},
            {"晚间第一节",18,55, 20,10},
            {"讨论",     20,10, 20,30},
            {"晚间第二节",20,30, 21,40},
            {"晚休",     21,40, 24, 0}
        }
        //时间表
        //支持调整与修改项目
    );
    static_assert(flush_time>0);
    static_assert(scl_size>0);
/*
//-------------------
*/

int main(){
    times a;
    while(1){
        int st=time(0);
        while(time(0)-st!=flush_time);
        #if RAND_MAX==INT_MAX
        system("clear");
        #else
        system("cls");
        #endif
        hm_times_t now((int)to_number(a.hours_24()),(int)to_number(a.minute()));
        if(show_nowtime){
            if(time_format=="default") cout<<"Time: "<<a.date()<<" "<<a.weekname()<<" "<<a.hours_24()<<":"<<a.minute()<<":"<<a.second()<<endl;
            else cout<<a.get_format(time_format)<<endl;
        }
        auto x=day[{(int)to_number(a.hours_24()),(int)to_number(a.minute())}];
        cout<<"Now "<<x.first<<endl;
        if(show_remain_times_line and x.second.second){
            if(show_percent) printf("%.0f%% ",continued_time(x.second.first,now)*100.0/x.second.second);
            if(show_scl) scroll_line(scl_size,continued_time(x.second.first,now)*1.0/x.second.second,scl_color,scl_color2);
            if(show_remain_times) cout<<" remain: "<<x.second.second-continued_time(x.second.first,now)<<" min"<<endl;
        }
    }
}

