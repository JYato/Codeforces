from collections import deque

def BrandesAlgorithm(V,A):
    C= dict((v,0) for v in V)
    for s in V:
        S=[]
        P=dict((w,[]) for w in V)
        sigma=dict((w,0) for w in V); sigma[s]=1
        d=dict((w,-1) for w in V); d[s]=0
        Q=deque([])
        Q.append(s)
        while(Q):
            v=Q.popleft()
            S.append(v)
            for w in A[v]:
                if d[w]<0:
                    Q.append(w)
                    d[w]=d[v]+1
                if d[w]==d[v]+1:
                    sigma[w]=sigma[w]+sigma[v]
                    P[w].append(v)
        cTemp=dict((v,0) for v in V)
        while S:
            w=S.pop()
            for v in P[w]:
                cTemp[v]=cTemp[v]+(sigma[v]/sigma[w])*(1+cTemp[w])
                if w!=s:
                    C[w]=C[w]+cTemp[w]

    for x in C:
        C[x]=C[x]/2
    return C

#V=[0,1,2,3,4,5]
#A=[[1,4],[0,2,3],[1,3,5],[1,2],[0,5],[2,4]]

V=[0,1,2,3,4,5,6,7]
A=[[1,3,4],[0,2,6],[2,3,5],[1,0],[0,7],[1,6],[1,2,3],[1,6,3]]

print(BrandesAlgorithm(V,A))
        
