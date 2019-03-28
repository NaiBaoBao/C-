#include <iostream>
using namespace std;
typedef struct node{
	int coef;
	int exp;
	struct node *next;
}node;
class Poly{
	private:
		node *head;
	public:
	Poly(){
		head=new node;
		head->next=NULL;
	}
	Poly(node *h){
		head=h;
	}
	void clear(){
		head->next=NULL;
	}
	void init(int n){
		node *p=head;
		for(int i=0;i<n;i++){
		node *current=new node;
		cin>>current->coef>>current->exp;
		current->next=NULL;
		p->next=current;
		p=p->next;
		}
	}
	void sort(bool (*paixu)(int,int));
	void add(const Poly B);
	void display(){
		node *p=head->next;
		if(p!=NULL){
			if(p->coef==1){
				if(p->exp==0)
				cout<<p->coef;
				else if(p->exp==1)
				cout<<'x';
				else
			    cout<<"x^"<<p->exp;
			}
			else{
				if(p->exp==0)
				cout<<p->coef;
				else if(p->exp==1)
				cout<<p->coef<<'x';
				else
				cout<<p->coef<<"x^"<<p->exp;
			}
		}
		p=p->next;
		while(p!=NULL){
		if(p->exp==1){
		    if(p->coef==1){
				cout<<" + x";
			}
			else if(p->coef==-1){
				cout<<" - x";
			}
			else if(p->coef>1){
				cout<<" + "<<p->coef<<'x';
			}
			else{
				cout<<" - "<<-p->coef<<'x';
			}
		}
		else{
			if(p->coef==1){
				cout<<" + x^"<<p->exp;
			}
			else if(p->coef==-1){
				cout<<" - x^"<<p->exp;
			}
			else if(p->coef>1){
				cout<<" + "<<p->coef<<"x^"<<p->exp;
			}
			else{
				cout<<" - "<<-p->coef<<"x^"<<p->exp;
			}
		}
		p=p->next;
		}
	}
};

void display2(node *head){
		node *p=head->next;
		if(p!=NULL){
			if(p->coef==1){
				if(p->exp==0)
				cout<<p->coef;
				else if(p->exp==1)
				cout<<'x';
				else
			    cout<<"x^"<<p->exp;
			}
			else{
				if(p->exp==0)
				cout<<p->coef;
				else if(p->exp==1)
				cout<<p->coef<<'x';
				else
				cout<<p->coef<<"x^"<<p->exp;
			}
		}
		p=p->next;
		while(p!=NULL){
		if(p->exp==1){
		    if(p->coef==1){
				cout<<" + x";
			}
			else if(p->coef==-1){
				cout<<" - x";
			}
			else if(p->coef>1){
				cout<<" + "<<p->coef<<'x';
			}
			else{
				cout<<" - "<<-p->coef<<'x';
			}
		}
		else{
			if(p->coef==1){
				cout<<" + x^"<<p->exp;
			}
			else if(p->coef==-1){
				cout<<" - x^"<<p->exp;
			}
			else if(p->coef>1){
				cout<<" + "<<p->coef<<"x^"<<p->exp;
			}
			else{
				cout<<" - "<<-p->coef<<"x^"<<p->exp;
			}
		}
		p=p->next;
		}
	}
bool Ascend(int a,int b){
	return a>b?true:false;
}

void Poly::sort(bool (*paixu)(int,int)){
	for(node *p=head->next;p->next!=NULL;p=p->next){
		for(node *q=p->next;q!=NULL;q=q->next){
			if(paixu(p->exp,q->exp)==true){
				int etemp,ctemp;
				ctemp=p->coef;
				p->coef=q->coef;
				q->coef=ctemp;
				etemp=p->exp;
				p->exp=q->exp;
				q->exp=etemp;
			}
		}
	}
}
void Poly::add(const Poly B){
	node *cHead=new node;
	cHead->next=NULL;
	node *pa=this->head->next;
	node *pb=B.head->next;
	node *pc=cHead;
	while(pa!=NULL&&pb!=NULL){
		if(pa->exp<pb->exp){
			node *current=new node;
			current->next=NULL;
			current->coef=pa->coef;
			current->exp=pa->exp;
			pa=pa->next;
			pc->next=current;
			pc=pc->next;
		}
		else if(pa->exp>pb->exp){
			node *current=new node;
	
			current->next=NULL;
			current->coef=pb->coef;
			current->exp=pb->exp;
			pb=pb->next;
			pc->next=current;
			pc=pc->next;
		}
		else{
			if(pa->coef+pb->coef==0){
				pa=pa->next;
				pb=pb->next;
			}
			else{
				node *current=new node;
			    current->next=NULL;
				current->coef=pa->coef+pb->coef;
				current->exp=pa->exp;
				pc->next=current;
				pc=pc->next;
				pa=pa->next;
				pb=pb->next;
			}
		}
	}
	if(pa!=NULL){
		pc->next=pa;
	}
	else if(pb!=NULL){
		pc->next=pb;
	}
	display2(cHead);
}
int main(){
	Poly A,B;
	int m,n;
	while(cin>>m>>n){
		A.clear();
		B.clear();
		A.init(m);
		B.init(n);
		A.sort(Ascend);
		B.sort(Ascend);
		A.add(B);
		cout<<endl;
	}
	return 0;
}
