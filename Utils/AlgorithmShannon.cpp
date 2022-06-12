#include "AlgorithmShannon.h"

void AlgorithmShannon::shannon(int l,int h,node s[])
{
    float pack1=0,pack2=0,diff1=0,diff2=0;
    int i,d,k,j;

    if((l+1)==h || l==h || l>h)
    {
        if(l==h || l>h)
            return;

        s[h].arr[++(s[h].top)]=1;
        s[l].arr[++(s[l].top)]=0;

        return;
    } else {
        for(i=l;i<=h-1;i++)
            pack1=pack1+s[i].pro;

        pack2=pack2+s[h].pro;
        diff1=pack1-pack2;

        if(diff1< 0)
            diff1=diff1*-1;
        j=2;

        while(j!=h-l+1)
        {
            k=h-j;
            pack1=pack2=0;

            for(i=l;i<=k;i++)
                pack1=pack1+s[i].pro;

            for(i=h;i>k;i--)
                pack2=pack2+s[i].pro;
            diff2=pack1-pack2;

            if(diff2< 0)
                diff2=diff2*-1;
            if(diff2>=diff1)
                break;

            diff1=diff2;
            j++;
        }
        k++;

        for(i=l;i<=k;i++)
            s[i].arr[++(s[i].top)]=0;
        for(i=k+1;i<=h;i++)
            s[i].arr[++(s[i].top)]=1;

        shannon(l,k,s);
        shannon(k+1,h,s);
    }
}

std::vector<float> AlgorithmShannon::probability(std::string word) {

    std::string text = word;
    size_t size=text.size();

    int count = 0;
    std::map <char, float> m;
    std::vector<float> prob = {0, 0, 0, 0, 0};

    for (size_t i = 0; i < size; i++)
    {
        if(isupper(text[i]))
            text[i]=tolower(text[i]);
        if(isalpha(text[i]))
            m[text[i]]++;
    }

    for (auto i = m.begin(); i != m.end(); i++) {
        prob[count] = (i->second) / 5;
        count += 1;
    }

    return prob;
}

void AlgorithmShannon::solver(std::vector<char> alphabet, std::string &word, std::vector<std::string> &binary, int &res, int n)
{
    int i;
    float total=0;
    char ch[10];
    node temp;
    for(int i = 0;i < n;i++)
    {
        strcpy(massive[i].sym,ch);
    }

    std::vector<float> out_prob = probability(word);

    // считаем вероятность
    for(i = 0; i < n; i++)
    {
        massive[i].pro = out_prob[i];
        total = total+massive[i].pro;

        if(total > 1)
        {
            printf("\t\tThis probability is not possible.Enter new probability");
            total = total - massive[i].pro;
            i--;
        }
    }

    massive[i].pro = 1 - total;

    for(int j = 1; j <= n-1; j++)
    {
        for(i = 0; i < n-1; i++)
        {
            if((massive[i].pro)>(massive[i+1].pro))
            {
                temp.pro = massive[i].pro;
                strcpy(temp.sym, massive[i].sym);
                massive[i].pro = massive[i+1].pro;
                strcpy(massive[i].sym, massive[i+1].sym);
                massive[i+1].pro=temp.pro;
                strcpy(massive[i+1].sym,temp.sym);
            }
        }
    }

    for(int i=0; i < n; i++)
        massive[i].top=-1;

    shannon(0, n - 1, massive);

    std::string plus;

    for(int i = n-1; i >= 0; i--)
    {
        for(int j=0; j <= massive[i].top; j++) {
            plus.insert(j, std::to_string(massive[i].arr[j]));
            res += 1;
        }

        binary.push_back(plus);
        plus.clear();
    }
}

