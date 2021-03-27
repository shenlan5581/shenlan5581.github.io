char** split(const string& s, const string& seperator,int* count) {
        vector<string> result;
        unsigned int posBegin = 0;
        unsigned int posSeperator = s.find(seperator);
       while (posSeperator !=-1 ) {
           result.push_back(s.substr(posBegin, posSeperator - posBegin));//
           posBegin = posSeperator + seperator.size(); // 分隔符的下一个元素
           posSeperator = s.find(seperator, posBegin);
      }
       if (posBegin != s.length()) // 指向最后一个元素，加进来
            result.push_back(s.substr(posBegin));
       *count=result.size(); //元素个数
       char ** ret=(char**)malloc((*count)*sizeof(char*)); //申请内存
       char ** head=ret;//第一个元素
       for(int i=0;i<*count;i++) { //size()容器中实际数据个数
           int size= result[i].length();
           *ret=(char*)malloc((size)*sizeof(char));//申请字符内存
            strcpy(*ret,(result[i]).c_str());
            ret+=sizeof(char*);
       }
       for (int i=0;i<*count;i++){
       cout<<*head<<endl;
       head+=sizeof(char*);
       }
       return head;
}
    char ** he = (char**)malloc(2 * sizeof(char*));
    char **i =he;
    printf("%p",&(*he));
    printf("%s","-");
    printf("%p",&i[0]);
    printf("%s","--------");
    he+=1;  
（这里是个天坑，如果指针有类型，那么+1= 地址偏移了1个类型的长度(8位)，而不能sizeof(char*)这样会偏移8个类型长度64位
    printf("%p",&(*he));
    printf("%s","-");
    printf("%p",&i[1]);