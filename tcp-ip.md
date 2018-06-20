## <center>TPC/IP</center>
### 陌生词汇
 |*|*|*|*|*|*|*
 |-|-|-|-|-|-|-
### 常见命令
```sh
#启用网桥#
Linux# brctl addbr br0
#将br0与eth0桥接，从etho接收的帧会被br0处理，从br0发送的被eth0处理
Linux# brctl addif br0 eth0
Linux# brctl addif br0 eth1
#从<ifname>将<brname>分离出来
Linux# brctl showmacs <brname>
#shows a list of learned MAC addresses for this bridge.
Linux# brctl delif <brname> <ifname>
Linux# ifconfig etho up
Linux# ifconfig eth1 up
Linux# ifconfig br0 up
```
### DNS
找出`12.17.136.129`相关的主机名称
```sh
 nslookup
 server f.in-addr-servers.arpa
 set type=ptr
 129.128/25.136.17.12.in-addr-arpa
 server dbru.br.ns.els-gms.att.net
 129.128/25.136.17.12.in-addr.arpa
 server ns2.intel-research.net
 129.128/25.136.17.12.in-addr.arpa
 
```
### TCP
* `-a` 能够报告所有的网络节点
* `-n` 以十进制数的形式打印IP地址，还会打印端口
* `-t` 选择`tcp` 节点
* 处于 `ESTABLISHED`状态的节点不能接收`SYN`报文段，而处于`LISTEN`状态的节点则不能接收数据报。
```sh
netstat -a -n -t
```
* `net.ipv4.tcp_max_syn_backlog`(默认1000),设置`SVN_RCVD`状态的连接数目
* `net.core.somaxconn`(默认为128),设置未完成连接`backlog`,已完成三次握手
* `Karn`算法:
 1. 排除二义性数据，重传
 2. 退避系数加倍
* `Nagle`算法
* 慢启动
* 拥塞避免
* CWV算法
  1. 查看距离上次发送操作是否超过一个RTO，如果超过
  2. 更新 ssthresh值 - 设置max(ssthresh,(3/4)*cwnd)
  3. 每经一个空闲RTT时间，cwnd值就减半，但不小于1 SMSS
  4. 对于应用受限阶段(非空闲阶段)，执行相似操作
    1. 已使用的窗口大小记为W_used
    2. 更新ssthresh值-设为max(ssthresh,(3/4)*cwnd)
    3.cend设为cwnd和W_used的平均值
