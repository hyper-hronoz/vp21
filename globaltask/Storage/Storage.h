class Storage {
 private:
    static Storage *storage;
    Storage();

 public:
    Storage(const Storage &other) = delete;

    void operator=(const Storage &) = delete;

    static Storage *GetInstance() {
        if (Storage::storage == nullptr) {
            storage = new Storage();
        }
        return storage;
    }

    template<class T> void save(T t);

    template<class T> T get(T t);
};
