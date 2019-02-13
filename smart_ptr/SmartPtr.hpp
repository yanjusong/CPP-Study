/* 模板类作为友元时要先有声明 */
template <typename T>
class SmartPtr;

/*
 * 辅助类
 */
template <typename T>
class U_Ptr
{
  private:
    /* 该类成员访问权限全部为private，因为不想让用户直接使用该类 */
    friend class SmartPtr<T>;

    /*
     * @brief: 构造函数
     *      构造函数的参数为基础对象的指针
     */
    U_Ptr(T *ptr) : p_(ptr), count_(1) {}

    /*
     * @brief: 析构函数
     *      构造函数的参数为基础对象的指针
     */
    ~U_Ptr() { delete p_; }

    int count_; /* 引用计数 */
    T *p_;      /* 基础对象指针 */
};

/*
 * 智能指针类
 */
template <typename T>
class SmartPtr
{
  public:
    /*
     * @brief: 构造函数
     */
    SmartPtr(T *ptr) : uptr_(new U_Ptr<T>(ptr)) {}

    /*
     * @brief: 复制构造函数
     */
    SmartPtr(const SmartPtr<T> &rhs) : uptr_(rhs.uptr_) { ++uptr_->count_; }

    /*
     * @brief: 赋值构造函数
     */
    SmartPtr &operator=(const SmartPtr<T> &rhs)
    {        
        if (this == &rhs)
            return *this;
        
        ++rhs.uptr_->count_;      /* 首先将右操作数引用计数加1 */
        if (--uptr_->count_ == 0) /* 然后将引用计数减1，可以应对自赋值 */
            delete uptr_;
        uptr_ = rhs.uptr_;
        return *this;
    }

    /*
     * @brief: 重载*操作符
     */
    T &operator*()
    {
        return *(uptr_->p_);
    }

    /*
     * @brief: 重载->操作符
     */
    T *operator->() 
    {
        return uptr_->p_; 
    }

     /*
     * @brief: 获取引用计数
     */
    int use_count()
    {
        return uptr_->count_;
    }

    /*
     * @brief: 析构函数
     */
    ~SmartPtr()
    {                         
        if (--uptr_->count_ == 0) /* 当引用计数减为0时，删除辅助类对象指针，从而删除基础对象 */
            delete uptr_;
    }

  private:
    U_Ptr<T> *uptr_; /* 辅助类对象指针 */
};