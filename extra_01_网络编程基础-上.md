# 1. 网络编程基础
- 什么是网络？
    - 普通网络用户
        - 资源库，信息媒体，虚拟世界，通讯媒介, ......
    - 应用程序开发者
        - 数据收发的通道（open, send, receive, close )
    - 网络设备开发者
        - 数据收发器，设备连接方式, 通信协议, ......

- 典型的网络形态 - 局域网（LAN )
    ![](vx_images/.png)


- 典型的网络形态 - 广域网（WAN )
    ![](vx_images/.png)

- 网络基本概念一
    - MAC 地址（硬件地址）：
        - 网络设备出厂时设定的全球唯一硬件地址
    - 网络地址（软件地址）：
        - 每一台网络主机都有唯一的地址（如：192.168.12.1 )
    - 网络端口 :
        - 每一台网络主机可以通过不同端口进行多路通信（如：80端口）

- 网络基本概念二
    - 交换机：端到端数据转发
        - 基于硬件地址实现不同设备间的数据转发
        - 特点：工作层次低，转发速度快
    - 路甶器：决定数据转发路线，执行转发操作
        - 基于软件地址实现不同网络间的数据转发
        - 特点：能够选择数据通道，实现通信控制

# 2. 实例分析 交换机和路由器

- 问题
    常见的那种 WIFI 设备是交换机还是路甶器？

# 3. 小结
- 互联网甶各种终端，主机，交换机麻]路甶器构成
- 物理上位置接近的设备通过交换机连接成局域网
- 不同的局域网通过路甶器互连构成广域网
- 交换机和路甶器都是数据转发器，但是扮演的角色不同
