#include<iostream>
using namespace std;

struct term{
    float coe;//ϵ��
    int exp;//ָ��
    struct term *next;//term���͵�ָ�룬����next,����ָ����һ��
};

typedef struct term Polynomial;//Ϊterm������Polynomial

void CreatPolyn(Polynomial *P){//�������ݣ�����һ������ʽP
    int n;
    cout<<"input number of terms:"<<endl;
    cin>>n;//����n�Ƕ���ʽ������
    Polynomial *current,*node=P;//��������Polynomial���͵�ָ�룬һ��currentָ���ڵĽڵ㣨ÿ���¿��ٵģ�
    //һ��node��ָͷ�ڵ㣬��Ϊ����Pֻ��һ���ڵ㣬֮��ÿ�ζ����ƣ���current֮ǰ�Ľڵ�
    for(int i=0;i<n;i++){//ͷ�ڵ��֮��n���ڵ㣨n�
    current=new Polynomial;//�����½ڵ�
    current->next=NULL;//�½ڵ����û�����ŵĽڵ�
    cout<<"input coe and exp:"<<endl;
    cin>>current->coe>>current->exp;//�����½ڵ��ϵ����ָ��
    node->next=current;//��current����node����һ����ͷ�ڵ㣬֮����β�ڵ㣩֮��Ϊ��һ���ڵ�
    node=node->next;//node���ƣ������ϵ�current��Ϊ�µ�node��Ҳ��β�ڵ�
    }
}

void PrintPolyn(Polynomial *P){//�������ʽP
    Polynomial *p=P->next;//PΪ����ʽP�ĵ�һ�ͷ�ڵ���һ���ڵ㣩
    if(p!=NULL){//����ʽP��Ϊ��ʽ
    cout<<p->coe<<"x^"<<p->exp;//�����һ�����3x^2
    p=p->next;//pָ����һ��
    }
    while(p!=NULL){//�����һ�����
        cout<<"+"<<p->coe<<"x^"<<p->exp;//���+4x^3����
        p=p->next;//ָ����һ��
    }
    cout<<endl;//����ʽ����֮꣬����
}

bool Ascending(int a,int b){
    return a<b?true:false;//a<bʱΪtrue
}

bool Equal(int a,int b){
    return a==b?true:false;//a=bʱΪtrue
}

bool Descending(int a,int b){
    return a>b?true:false;//a>bʱΪtrue
}

void Sort(Polynomial *P,bool(*compare)(int,int)){//����ʽ�ڲ����򣬺������������룬����������ĸ�ʽ�ȼ��������Ժ��н���
    if(P->next!=NULL){
        for(Polynomial *p=P->next;p->next!=NULL;p=p->next){//�ӵ�һ����һ��
            for(Polynomial *q=p->next;q!=NULL;q=q->next){//p������֮��������Ƚ�
                if(!compare(p->exp,q->exp)){//����ȽϽ��������/��/ƽ
                    float ctemp=p->coe;
                    p->coe=q->coe;
                    q->coe=ctemp;//����p,q�����ϵ��
                    int etemp=p->exp;
                    p->exp=q->exp;
                    q->exp=etemp;//����p,q�����ָ��
                }
            }
        }
    }
}

Polynomial* AddPolyn(Polynomial *a,Polynomial *b){//����ʽ��Ӻ���
    Polynomial *c=new Polynomial;//c����ʽ����װa��b�ĺ�
    c->next=NULL;
    Sort(a,Ascending);//����ʽa��������
    Sort(b,Ascending);//����ʽb��������
    Polynomial *pc=c;//pc->next����װÿһ������
    Polynomial *pa=a->next;//pa��a��ÿһ��ӵ�һ�ʼ
    Polynomial *pb=b->next;//pb��b��ÿһ��ӵ�һ�ʼ
    while(pa!=NULL&&pb!=NULL){//��a��b������û�д��������ʱ
        if(pa->exp<pb->exp){//a����ָ����С����Ϊ��������a����
            pc->next=pa;
            pc=pc->next;
            pa=pa->next;//a��c��˳����һ��
        }
        else if(pa->exp>pb->exp){//b����ָ����С����Ϊ��������b����
            pc->next=pb;
            pc=pc->next;
            pb=pb->next;//b��c˳����һ��
        }
        else{//a��b��ָ����ͬ
            if(pa->coe+pb->coe!=0){//����ϵ���Ͳ�Ϊ0
                Polynomial *node=new Polynomial;//����һ���½ڵ�
                node->coe=pa->coe+pb->coe;//ϵ����
                node->exp=pb->exp;//ָ��Ų
                node->next=NULL;//����ָ��
                pc->next=node;//�½ڵ㸳��pc��һ��
                pc=pc->next;//pc��������
            }
            pa=pa->next;//ϵ����ֱͬ�Ӹɵ�
            pb=pb->next;
        }
    }
    if(pa!=NULL){//��b���ˣ�a������
    pc->next=pa;
    }
    else if(pb!=NULL){//��a���ˣ�b������
    pc->next=pb;
    }
    return c;
}

Polynomial* SubPolyn(Polynomial *a,Polynomial *b){//����
    Polynomial *pb=b->next;//pbΪb��һ��
    while(pb!=NULL){//��b��ÿһ�ȡ�෴���ټ�����
        pb->coe=-1*pb->coe;
        pb=pb->next;
    }
    Polynomial *c=AddPolyn(a,b);
    return c;
}

Polynomial* MulPolynK(Polynomial *a,float coe,int exp){//�ֲ����
    Polynomial *c=new Polynomial;//�����½ڵ㣬һ���һ��ʽ��
    c->next=NULL;
    Polynomial *cp,*node=c;//��cp���н�c��ÿһ�node���ƶ�ָ��
    Polynomial *p=a->next;//pָ��a����ʽ��ÿһ��
    while(p!=NULL){
        cp=new Polynomial;
        cp->next=NULL;
        cp->coe=p->coe*coe;//ÿһ���ϵ�����Թ̶����ϵ��
        cp->exp=p->exp+exp;//�����ָ��������Ӻ�
        node->next=cp;//���������½ڵ�
        node=node->next;//��һ�����
        p=p->next;
    }
    return c;
}

Polynomial* MulPolyn(Polynomial *a,Polynomial *b){//���
    Polynomial *pa=a->next;
    Polynomial *pb=b->next;
    Polynomial *c=new Polynomial;//balabala
    c->next=NULL;
    while(pb!=NULL){//��b��ÿһ���ó����ֱ��a��ˣ��ۼ�
        Polynomial *cp=MulPolynK(a,pb->coe,pb->exp);
        c=AddPolyn(c,cp);
        pb=pb->next;
    }
    return c;
}

int main(){
    Polynomial *P=new Polynomial;//����һ������ΪP��Polynomial���͵Ľṹ
    P->next=NULL;//P��һ���ڵ㣬ָ���
    CreatPolyn(P);
    PrintPolyn(P);
    Polynomial *Q=new Polynomial;//��������ΪQ��Polynomial���͵Ľṹ
    Q->next=NULL;//QͬP
    CreatPolyn(Q);
    PrintPolyn(Q);
    Polynomial *A;//A��Polynomial���͵Ľṹ
    //A=AddPolyn(P,Q);
    // cout<<"����ʽ��ӵĺͣ�"<<endl;
    //A=SubPolyn(P,Q);
    //cout<<"����ʽ����Ĳ"<<endl;
    A=MulPolyn(P,Q);
    cout<<"����ʽ��˵Ļ�:"<<endl;
    PrintPolyn(A);//���
    return 0;
}