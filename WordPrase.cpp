#include "WordPrase.h"
using namespace std;




string  heng[6] = { "i", "+", "*", "(", ")", "#", };
string  shu[5] = { "E", "E'", "T", "T'", "F", };

void addQuenueToStack(queue<string>* que, stack<string> * stk){

	string str[10];
	int i = -1;
	bool flag = false;
	
	
	
	while (!que->empty())
	{
		i++;
	  str[i]=que->front();
	 if (str[i] == "^"){
		
		 flag = true;
	  }
		que->pop();

	}
	if (flag){
	
		stk->pop();
		return;
	}

	stk->pop();



	while (i>-1)
	{
		stk->push(str[i]);
		i--;
	}
}

int searchIDinShu(string str){
	
	int i = -1;
	bool flag = false;
	while (true)
	{
		i++;
		if (i > 4){
			i = -1;
			break;
		}
		if (shu[i] == str){
			flag = true;
			break;
			
		}
			
	}

	if (!flag)
		return -1;
	return i;
}

int searchIDinHeng(string str){

	int i = -1;
	bool  flag = false;
	while (i<5)
	{
		i++;
		if (heng[i] == str){
			flag = true;
			break;
			
		}
	}
    
	if (!flag)
		return -1;
 return i;
}

void formPrint(int id ,stack<string> stc,string chuan,int index,queue<string> que,int shuid,int flag){
	    
	cout << id << "     "<<"#";
	int kk = 0;
	string shuchu[20];
	while (!stc.empty())
	{    
	    shuchu[kk]=stc.top();
		stc.pop();
		kk++;
	}
	while (kk>=0)
	{
		cout << shuchu[kk];
		kk--;
	}
	cout << "			";

	int index1 = index;
	while (index1 < chuan.length())
	{
		cout << chuan[index1];
		index1++;
	}

	cout << "			";
	if (flag == 1){
	
		cout << shu[shuid] << "->";
		while (!que.empty())
		{
			cout << que.front();
			que.pop();

		}
	}
	else
	{
		cout << chuan[index - 1] << "匹配";
	}

	cout << "" << endl;
}
int main(){



	stack<string> m_stk;

	queue<string>  table[6][6];
	//构造表格
	queue<string> a;
	a.push("T");
	a.push("E'");
	table[0][0] = a;

	queue<string> b;
	b.push("T");
	b.push("E'");
	table[0][3] = b;


	queue<string> c;
	c.push("+");
	c.push("T");
	c.push("E'");
	table[1][1] = c;

	queue<string> d;
	d.push("^");
	table[1][4] = d;

	queue<string> e;
	e.push("^");
	table[1][5] = e;


	queue<string> f;
	f.push("F");
	f.push("T'");
	table[2][0] = f;

	queue<string> g;
	g.push("F");
	g.push("T'");
	table[2][3] = g;


	queue<string> h;
	h.push("^");
	table[3][1] = h;


	queue<string> k;
	k.push("*");
	k.push("F");
	k.push("T'");
	table[3][2] = k;

	queue<string> m;
	m.push("^");
	table[3][4] = m;


	queue<string> mff;
	mff.push("^");
	table[3][5] = mff;


	queue<string> pf;
	 pf.push("i");
	table[4][0] = pf;
	
	queue<string> jj;
	jj.push("(");
	jj.push("E");
	jj.push(")");

	table[4][3] = jj;
	//i+i*i#


	//得到输入的匹配
	cout << "请输入串" << endl;
	
	string chuan ;

	cin >>chuan;
	
	
	bool isPiPei = true;
	/*char chuann[10];
	chuan.copy(chuann, chuan.length(), 0);
	*(chuann + chuan.length()) = '/0';*/

	m_stk.push("E");


	int index = 0;
	int id = 0;
	while (true)
	{ 
		char a = chuan[index];
		
		string dtt;
		dtt += a;
		id++;


	

		int heng =searchIDinHeng(dtt);
		if (m_stk.empty()){
			cout << id << "	#			" << "#"<<"		"<<"	接受"<<endl;
			break;
		}
	
		int shu = searchIDinShu(m_stk.top());
	
	
		//如果栈顶元素为终结符栈顶弹出输入串向后移位
		if (searchIDinHeng(m_stk.top())!=-1){   

			if (index > chuan.length()){
				break;
			}
			
			index++;
			m_stk.pop();
			formPrint(id, m_stk, chuan, index, table[0][heng], shu, -1);
		}
		else
		{ //栈顶元素为非终结符时将输入匹配亚茹栈内
			if (heng >= 0 && heng <= 5 && shu <= 4 && shu >= 0){

				queue<string> que = table[shu][heng];


				if (que.empty()){
					isPiPei = false;
					break;
				}
				formPrint(id, m_stk, chuan, index, table[shu][heng], shu, 1);
				
				addQuenueToStack(&que, &m_stk);
				
				
			}
			
		}
	   

	}
   


	
	if (isPiPei == false){
		cout << "匹配失败";
		
	}
	
	system("pause");
	return 0;
 }