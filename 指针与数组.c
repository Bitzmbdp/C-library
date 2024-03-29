题目：

int main()
{
  char* a[] = { "ENTER","NEW","POINT","FIRST" };
  char** pa[] = { a + 3,a + 2,a + 1,a };
  char*** paa = pa;
  printf("%s\n",**++paa);
  printf("%s\n", *-- * ++paa + 3);
  printf("%s\n", *paa[-2] + 3);
  printf("%s\n", paa[-1][-1] + 1);
  return 0;
}

首先，我们要搞明白地址的分配；
a先和[]结合，代表是一个数组，数组的每个类型是char*的类型；然后可推理pa，可以自己画图理解，因为git不能粘贴图像，所以无法给大家展示，
（具体图像可看我的51CTU博客，id是稚名不带撇）
写到这里，就基本上懂一半啦 
然后根据题意：paa所存的地址就是a+3的这个地址
先看第一个​**++paa​：先算++paa，此时paa指向a+2
先解引用一次，指向第三个​char*​，再解引用一次，指向“POINT”。打印出来就是​​ POINT ​​啦。
再看​*-- * ++paa + 3​：老样子，和上面一样判断，先判断​++paa​，此时​paa​存着​a+1​的地址，再解引用，指向第二个​char*​，还有一个 “--” ，指向第一个​char*​，再解引用，指向E的地址，外面还有个+3，指向“ENTER”的第二个E。
这样就解决啦，只要弄清楚地址，是不是就很简单滴捏？  所以打印出来的是​​ ER ​​。
再来看第三个，​*paa[-2] + 3​：解释这个就要先了解知道​paa[-2]​是等价于​*(paa-2)​的，所以这个式子可以写成​**（paa-2）+3​，老规矩，先分析；此时​paa​存着​a+1​的地址，​paa-2​，就变成了存着​a+3​的地址了，解引用一次。指向​a+3​，再解引用一次，指向第四个​char*​，然后再解引用一次，指向“FIRST"，别忘记外面还有个​+3​哦 ，和上面一样的道理。
所以打印出来​​ ST ​​ 。
紧接着，我们来看​paa[-1][-1] + 1​：首先第一步，和上面一样，我i们要先转换​paa[-1][-1]​，会上面这题，那么我感觉这题也没多大问题，这个可以转换成​*（*（paa-1）-1）​，此时​paa​存着​a+1​的地址，所以​paa-1​就是存着的​a+2​的地址啦，然后解引用，指向​a+2​，还有个​-1​，所以​a-2​里存着的就是第二个​char*​的地址了，再解引用一次，指向​ NEW ​，但是外面的​+1​不能忘记，此时指向的是​ E ​。
所以打印出来的就是​​ EW ​​啦。
既然都看到这儿了，制作不易，求各位老爷们给个三连，拜托了❤❤❤
