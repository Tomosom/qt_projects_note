# 1. 软件开发流程 (同 : computer_fundamental:25_项目开发的前期设计)

- 什么是<font color=red>软件开发流程</font>？
    - 通过<font color=red>一系列步骤</font>保证软件产品的顺利完成
    - 软件产品在生命期内的<font color=red>管理方法学</font>

- 软件开发流程的本质
    - 开发流程<font color=red>与具体技术无关</font>
    - 开发流程是<font color=red>开发团队必须遵守的规则</font>

- 常见软件开发流程
    - 即兴模型 (Build-and-Fix Model)
    - 瀑布模型 (Waterfall Model)
    - 增量模型  (Incremental Model)
    - 螺旋模型 (Spiral Model)
    - 敏捷模型 (Agile Modeling)

- 即兴模型（Build-and-Fix Model)
    - 与最终用户交流后立即开始进行开发
    - <font color=red>没有需求分析和需求发掘的过程</font>
    - <font color=red>没有整体设计以及规划的过程</font>
    - <font color=red>没有相关软件文档，维护性差</font>

- 瀑布模型 (Waterfall Model)
    - 通过<font color=red>自上而下</font>的步骤进行软件开发
    - 每个<font color=red>开发步骤</font>都是<font color=red>不可逆</font>的

    ![](vx_images/031_1.png)
    > 适用 预研性项目

- 增量模型 （Incremental Model)
    - 将系统功能分解为<font color=red>互不重叠</font>的子功能
    - <font color=red>每次全力实现一个子功能</font>
    - 子功能全部完成后系统开发结束

    ![](vx_images/031_2.png)
    > 待优化 : 如何更好地适配用户需求

- 螺旋模型 （Spiral Model)
    - 采用<font color=red>一种迭代的方法</font>来进行系统开发
    - 软件项目分解成<font color=red>多个不同的版本</font>完成
    - <font color=red>每个版本的开发过程都需要用户参与</font>
    - 根据前一个版本的反馈计划下一个版本

    ![](vx_images/031_3.png)
    > 适用用用类型的软件开发, 比如社交软件
    > 缺点 : 对于一些私人订制的软件有所缺陷, 与用户接触的时间都是进行下一个版本开发的时候

- 敏捷模型（Agile Modeling )
    - <font color=red>一切从简</font>
    - <font color=red>拥抱变化</font>
    - <font color=red>高效工作</font>
    - <font color=red>持续开发</font>

    ![](vx_images/031_4.png)

# 2. 项目中的开发流程
- 问题
    文本编辑器项目如何选择软件开发流程？

- <font color=red>增量模型</font>适合于文本编辑器的开发
    - 需求相对固定
    - 功能之间的耦合性弱

    第1阶段 :
    ![](vx_images/031_5.png)

# 3. 实验 项目阶段性测试
实验目录：[031_Software_Development_Process_Description](vx_attachments\031_Software_Development_Process_Description)
前面章节notepad代码存在的问题
使用beyond compare对比bug改动

- 内存泄漏测试（检查可疑之处，自行分析）
    1. Linux下 : 分析 -> Valgrind 内存分析器 -> 等待程序运行起来 -> 关闭程序 -> 结果会显示在面板。
    ![](vx_images/031_e1.png)
    2. menu未指定父对象，添加打印调试查看`addMenu()`是否会自动添加父对象（结论：没有）。
    3. 指定父对象，解决bug。
    4. 再次检查，显示一些Qt平台自身的可能风险，相信Qt平台，可不用管。

# 4. 小结
- 软件开发流程是<font color=red>开发团队遵守的一系列规则</font>
- 软开发流程的意义在于<font color=red>保证产品的质量和进度</font>
- 业界已经存在了<font color=red>多种开发流程</font>的模型
- 每一种软件开发流程都有特定的适用范围
- 课程中容易采用<font color=red>增量模型</font>进行项目开发
