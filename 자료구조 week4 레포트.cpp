#pragma once

#include <cstdio>
#include <cstring>
#define MAX_CHAR_PER_LINE 1000

class Line {
   char data[MAX_CHAR_PER_LINE];
public:
   Line(char* line = "") { strcpy(data, line); }
   void print(FILE* fp = stdout) { fprintf(fp, "%s", data); }
   bool hasData(char* str) { return strcmp(str, data) == 0;}
};

class Node : public Line {
   Node* link;
public:
   Node(char* str = "") : Line(str), link(NULL) {}
   void setLink(Node* p) { link = p; }
   Node* getLink() { return link; }
   void insertNext(Node* p) {
      if(p != NULL) {
         p->link = link;
         link = p;
      }
   }
   Node* removeNext() {
      Node* removed = link;
      if(removed != NULL) link = removed->link;
      return removed;
   }
   
};

class LinkedList {
protected:
   Node org;
public:
   LinkedList(): org("") {}
   ~LinkedList() { clear(); }
   void clear() {
      while(!isEmpty()) delete remove(0);
   }
   Node* getHead() { return org.getLink(); }
   bool isEmpty() { return getHead() == NULL; }
   Node* getEntry(int pos) {
      Node* n = &org;
      for(int i = -1; i < pos; i++, n=n->getLink()) if(n == NULL) break;
      return n;
   }
   void insert(int pos, Node* n) {
      Node* prev = getEntry(pos-1);
      if(prev != NULL) prev->insertNext(n);
   }
   Node* remove(int pos) {
      Node* prev = getEntry(pos-1);
      return prev->removeNext();
   }
   Node* find(char* str) {
      for(Node* p = getHead(); p != NULL; p = p->getLink()) if(p->hasData(str)) return p;
   }
   void replace(int pos, Node* n) {
      Node* prev = getEntry(pos-1);
      if(prev != NULL) {
         delete prev->removeNext();
         prev->insertNext(n);
      }
   }
   int size() {
      int cnt = 0;
      for(Node* p = getHead(); p != NULL; p=p->getLink()) cnt++;
      return cnt;
   }
};

class LineEditor : public LinkedList {
public:
   void Display(FILE *fp = stdout) {
      int i = 0;
      for(Node *p = getHead(); p != NULL; p=p->getLink(), i++) {
         fprintf(stderr, "%3d", i);
         p->print(fp);
      }
   }
   void InsertLine() {
      int position;
      char line[MAX_CHAR_PER_LINE];
      printf("  입력행 번호: ");
      scanf("%d", &position);
      printf("  입력행 내용: ");
      fflush(stdin);
      fgets(line, MAX_CHAR_PER_LINE, stdin);
      
      insert(position, new Node(line)); 
   }
   void DeleteLine() {
      printf("  삭제행 번호: ");
      int position; 
      scanf("%d", &position);
      delete remove(position);
   }
   void ReplaceLine() {
      int position;
      char line[MAX_CHAR_PER_LINE];
      printf("  변경행 번호: ");
      scanf("%d", &position);
      printf("  변경행 내용: ");
      fflush(stdin);
      fgets(line, MAX_CHAR_PER_LINE, stdin); 
      
      replace(position, new Node(line));
   }
   void LoadFile(char *fname) {
      FILE *fp = fopen(fname, "r");
      if(fp != NULL) {
         char line[MAX_CHAR_PER_LINE];
         while(fgets(line, MAX_CHAR_PER_LINE, fp)) insert(size(), new Node(line));
      }
      fclose(fp);
   }
   void StoreFile(char *fname) {
      FILE *fp = fopen(fname, "w");
      if(fp != NULL) {
         Display(fp);
         fclose(fp);
      }
   }
   void FindReplace(FILE *fp = stdout) {
      int i = 0;
      
      char fline[MAX_CHAR_PER_LINE];
      char cline[MAX_CHAR_PER_LINE];
      
      printf("  찾을 문자열: ");
      fflush(stdin);
      fgets(fline, MAX_CHAR_PER_LINE, stdin);
      
      printf("  바꿀 문자열: "); 
      fflush(stdin);
      fgets(cline, MAX_CHAR_PER_LINE, stdin);
      
      for(Node *p = getHead(); p != NULL; p=p->getLink(), i++) {
         if(p->hasData(fline)) {
            delete remove(i);
            insert(i, new Node(cline));
            break;
         }
      }
      return;
   }
};

void Usage() {
   printf("[메뉴 선택] i-입력, d-삭제, r-변경, h-찾아바꾸기, p-출력, l-파일읽기, s-저장, q-종료 => ");
}
int main() {
   LineEditor le;
   char command;
   
   do {
      Usage();
      command = getchar();
      switch(command) {
         case 'i': le.InsertLine(); break;
         case 'd': le.DeleteLine(); break;
         case 'r': le.ReplaceLine(); break;
         case 'h': le.FindReplace(); break;
         case 'p': le.Display(); break;
         case 'l': le.LoadFile("Test.txt"); break;
         case 's': le.StoreFile("Test.txt"); break;
         case 'q': break;
      }
      fflush(stdin);
   } while(command != 'q');
}
