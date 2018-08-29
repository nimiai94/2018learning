# -*- coding: utf-8 -*-
import numpy as np
import pandas as pd
import math
train=pd.read_csv('train.csv')
test=[6,130,8]
'''
0表示男 1表示女
sex,height,weight,foot_size
0,6,180,12
0,5.92,190,11
0,5.58,170,12
0,5.92,165,10
1,5,100,6
1,5.5,150,8
1,5.42,130,7
1,5.75,150,9
'''
#计算男女类下，高度、重量、脚长的均值和方差
male=[train.loc[train['sex']==0].mean(),train.loc[train['sex']==0].var()]
famela=[train.loc[train['sex']==1].mean(),train.loc[train['sex']==1].var()]

#朴素贝叶斯最后的 规则是 Y=P(Ck|X)=P(Ck)M(P(X|Ck))/P(X)  P(X)为常量 P(Ck)可以由训练数据求出 
# 根据链式规则和特征之间相互独立的设定，P(Ck)M(P(X|Ck)) =P(Ck)M(P(xi|Ck))

#计算各自的概率P(xi|Ck)
def probability_c(x,n,malefmale):
    return np.exp(-(x-malefmale[0][n])**2/(2*malefmale[1][n]))/(math.sqrt(2*math.pi*malefmale[1][n]))



resultmale=[]
resultfemale=[]
for i in range(1,4):
    resultmale.append(probability_c(test[i-1],i,male))
    resultfemale.append(probability_c(test[i-1],i,famela))

if np.cumprod(resultmale)[2]>np.cumprod(resultfemale)[2]:
    print('男')
elif np.cumprod(resultmale)[2]<np.cumprod(resultfemale)[2]:
    print('女')
else:
    print('不确定')
    
    
    
#使用sklearn中的朴素贝叶斯算法计算
#1、高斯朴素贝叶斯
from sklearn.naive_bayes import GaussianNB

X=train.iloc[:,1:]
y=train.iloc[:,0]

clf=GaussianNB()
clf.fit(X,y)

clf.set_params(priors=[0.5, 0.5])

print(clf.predict([[6,130,8]]))


#2、多项式朴素贝叶斯  
from sklearn.naive_bayes import MultinomialNB

#X=train.iloc[:,1:]
#y=train.iloc[:,0]

clf2=MultinomialNB(alpha=2.0,class_prior=None,fit_prior=False)
clf2.fit(X,y)

print(clf2.predict([[6,130,8]]))


#3、伯努利朴素贝叶斯  不论是test数据还是train的数据，预测的结果都是0 ，是不是说明该模型对于该数据是不合适的？？
from sklearn.naive_bayes import BernoulliNB

#X=train.iloc[:,1:]
#y=train.iloc[:,0]

clf3=BernoulliNB()
clf3.fit(X,y)

print(clf3.predict([X.iloc[7,:]]))