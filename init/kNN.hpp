#include "main.hpp"

void merge(pair<double, int>* arr, int l, int m, int r);
void mergeSort(pair<double, int> arr[], int l, int r);

template <typename T>
class List
{
public:
    //! Hàm của thầy
    virtual ~List() = default;
    virtual void push_back(T value) = 0;
    virtual void push_front(T value) = 0;
    virtual void insert(int index, T value) = 0;
    virtual void remove(int index) = 0;
    virtual T &get(int index) const = 0;
    virtual int length() const = 0;
    virtual void clear() = 0;
    virtual void print() const = 0;
    virtual void reverse() = 0;
    virtual void getArray(T *Array) const = 0;
    //! Hàm hỗ trợ thêm
    virtual List<T> *subList(int start, int end) = 0;
    virtual void printStartToEnd(int start, int end) const = 0;
};

//
// class Image
template <typename T>
class Image : public List<T>
{
private:
    class Node
    {
    public:
        T pointer;
        Node *next;

    public:
        Node(T pointer, Node *next = nullptr) : pointer(pointer), next(next) {}
    };

private:
    Node *head;
    Node *tail;
    int size;

public:
    Image()
    {
        head = tail = nullptr;
        size = 0;
    }
    ~Image()
    {
        this->clear();
    }

    Image(const Image& other) 
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
        Node* curr = other.head;
        while (curr != nullptr) {
            this->push_back(curr->pointer);
            curr = curr->next;
        }
    }
   
    void getArray(T* Array) const 
    {
        Node* tmp = head;
        for (int i = 0; i < size; i++) 
        {
            Array[i] = tmp->pointer;
            tmp = tmp->next;
        }
    }

    void push_back(T value)
    {
        // TODO: implement task 1
        Node* newNode = new Node(value); // Tạo một nút mới chứa giá trị cần thêm

        if (head == nullptr) 
        { 
            head = newNode;
            tail = newNode;
        } 
        else 
        {
            Node* temp = head;
            while (temp -> next != nullptr) 
            { 
                temp = temp -> next;
            }
            temp -> next = newNode; 
            tail = newNode; // Cho tail bang newNode
        }
        size ++;
    }
    void push_front(T value)
    {
        // TODO: implement task 1
        if (size == 0)
        {
            head = new Node(value, nullptr);
            tail = head;
        }
        else
        {
            Node* tmp = new Node(value, nullptr);
            tmp -> next = head;
            head = tmp;
        }
        size++;
    }
    void insert(int index, T value)
    {
        // TODO: implement task 1
        if(index < 0 || index > size) 
        {
            return;
        }

        //TODO: implement task 1
        Node *temp = new Node (value, nullptr);
        if (index == 0)
        {
            temp -> next = head;
            head = temp;
            size ++;
            return;
        }
        Node* current = head;
        for (int i = 1; i < index; i++) 
        { 
            current = current -> next;
        }

        // Chèn newNode vào sau current
        temp -> next = current -> next;
        current -> next = temp;
        size ++;
    }
    void remove(int index)
    {
        // TODO: implement task 1
        if(index < 0 || index >= size)
        {
            return;
        }
        if (index == 0) 
        {
            Node* temp = head;
            head = head -> next;
            delete temp;
            size --;
            return;
        }

        Node* previous = nullptr;
        Node* current = head;

        for (int i = 0; current != nullptr && i < index; i++) 
        {
            previous = current;
            current = current -> next;
        }
        // Kiểm tra xem index có hợp lệ không
        if (current == nullptr) 
        {
            return;
        }
        // Xóa phần tử tại vị trí index
        previous -> next = current -> next;
        size --;
        delete current;
    }
    T &get(int index) const
    {
        // TODO: implement task 1
        if(index < 0 || index >= this -> size)
        {  
            throw std::out_of_range("get(): Out of range");
        }
        Node *temp = head;
        for (int i = 0; i < index; i ++)
        {
            temp = temp -> next;
        }
        //TODO: implement task 1  
        return temp -> pointer;
    }
    int length() const
    {
        return size;
    }
    void clear()
    {
        // TODO: implement task 1
        while (head != nullptr) 
        {
            Node* temp = head;
            head = head ->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    void print() const
    {
         if(size == 0) cout << "nullptr" << endl;
        Node* temp = head;
        for(int i = 0; i < this->size; i++)
        {
            if(i == this->size - 1) cout << temp->pointer << endl;
            else cout << temp->pointer << " ";
            temp = temp->next;
        }
    }
    void reverse()
    {
        if (head == nullptr || head -> next == nullptr)
        {
            return;
        }
        Node *truoc = nullptr;
        Node *hientai = head;
        Node *sau = nullptr;
        while (hientai != nullptr)
        {
            sau = hientai -> next;
            hientai -> next = truoc;
            truoc = hientai;
            hientai = sau;
        }
        head = truoc;
    }
    void printStartToEnd(int start, int end) const
    {
        Node* temp = head;
        for(int i = 0; i < start; i++) temp = temp->next;
        for(int i = start; i < end && i < this->size; i++)
        {
            if(i == end - 1 || i == this->size - 1)
            {
                cout << temp->pointer;
            }
            else cout << temp->pointer << " ";
            temp = temp->next;
        }
    }
    List<T> *subList(int start, int end)
    {
        List<T>* result = new Image<T>();
        Node *temp = this -> head;
        for (int i = 0; i < start; i++)
        {
            if (temp == nullptr) 
            {
                return nullptr;
            }
            temp = temp -> next;
        }
        if (end > size)
        {
            for (int i = start; i < size; i ++)
            {
                if (temp == nullptr) 
                {
                    return nullptr;
                }
                result -> push_back(temp -> pointer); // Thêm dữ liệu từ phần cắt vào danh sách mới
                temp = temp -> next;
            }
        }
        else
        {
            for (int i = start; i < end; i++)
            {
                if (temp == nullptr) 
                {
                    return nullptr;
                }
                result -> push_back(temp -> pointer); // Thêm dữ liệu từ phần cắt vào danh sách mới
                temp = temp -> next;
            }
        }

        // Cach khac
        // for (int i = start; i < this -> size && i < end; i++)
        // {
        //     result -> push_back(temp -> pointer);
        //     temp = temp -> next;
        // }

        return result;
    }
};

class Dataset
{
private:
    List<List<int> *> *data;
    List<string> *nameCol;
    // You may need to define more
public:
    //! Hàm khởi tạo
    Dataset()
    {
        this->nameCol = new Image<string>();
        this->data = new Image<List<int> *>();
    }
    //! Hàm hủy
    ~Dataset()
    {
        for (int i=0;i<data->length();i++)
        {
        data->get(i)->clear();
        }
        //! xóa cập phát động của hàng chứa cột
        for(int i = 0; i< data->length(); i++)
        {
            delete this->data->get(i);
        }
        //! xóa data tự động gọi tới hàm hủy của image và gọi tới clear() để xóa các cấp phát động của data
        delete data;
        delete nameCol;
    }
    Dataset(const Dataset &other)
    {
        int col =  max(col, other.nameCol->length());
        this -> data = new Image<List<int>*>();
        if(other.data -> length() == 0) 
        {
            this -> nameCol = new Image<string>();
            this->nameCol = other.nameCol->subList(0, col);
            return;
        }
        // this -> nameCol = new Image<string>();
        this->nameCol = other.nameCol->subList(0, col);

        for (int i = 0; i < other.data -> length(); i++)
        {
            List<int> *tmp = new Image<int>();
            for (int j = 0; j < other.data -> get(i) -> length(); j++)
            {
                tmp -> push_back(other.data -> get(i) -> get(j)); 
            }
            this -> data -> push_back(tmp);
        }
    }
    Dataset &operator=(const Dataset &other)
    {
        if (this != &other) 
        { 
            // Xóa dữ liệu cũ
            delete data;
            delete nameCol;

            // Sao chép dữ liệu từ other
            this -> data = new Image<List<int>*>();
            this -> nameCol = new Image<string>();

            // Sao chép nameCol
            for (int i = 0; i < other.nameCol -> length(); i++) 
            {
                this -> nameCol -> push_back(other.nameCol -> get(i));
            }
            for (int i = 0; i < other.data->length(); i++) 
            {
                List<int>* sublist = new Image<int>(); // Tạo một subList mới để sao chép dữ liệu từ other
                List<int>* otherSublist = other.data -> get(i);
                for (int j = 0; j < otherSublist->length(); j++) 
                {
                    sublist->push_back(otherSublist -> get(j));
                }
                this->data->push_back(sublist);
            }
        }
        return *this;
    }
    List<string> *getnameCol() const
    {
        return nameCol;
    }
    List<List<int> *> *getData() const
    {
        // ! UPDATE file thay
        return data;
    }
    bool loadFromCSV(const char *fileName)
    {
        ifstream file(fileName);
        //* kiểm tra mở file
        if (file.is_open())
        {
            string str;
            int number;

            //* xử lý hàng đầu tiên chuyển , thành ' ' dùng thư viện stringstream
            file >> str;
            for (int i = 0; i < str.length(); i++)
            {
                if (str[i] == ',')
                    str[i] = ' ';
            }
            stringstream ss(str);
            while (ss >> str)
                nameCol->push_back(str);

            //* xử lý các hàng còn lại , thành ' ' dùng thư viện stringstream
            while (file >> str)
            {
                for (int i = 0; i < str.length(); i++)
                {
                    if (str[i] == ',')
                        str[i] = ' ';
                }
                stringstream ss(str);
                List<int> *temp = new Image<int>();
                while (ss >> number)
                    temp->push_back(number);
                data->push_back(temp);
            }
            return true;
        }
        return false;
    }
    void getShape(int &nRows, int &nCols) const
    {
        nRows = this->data->length();
        if(this->data->length() == 0) 
        {
            nCols = 0;
        }   
        else  
        {
            nCols = data->length() ? data->get(0)->length() : 0;
        }
    }
    void columns() const
    {
        // TODO: implement Task 2
        nameCol -> print();
    }
    void printHead(int nRows = 5, int nCols = 5) const
    {
        if (nRows <= 0 || nCols <= 0)
        {   
            return;
        }
        int numRows = data -> length();
        int numCols = nameCol -> length();
        if (data -> length() <= 0 || nameCol -> length() <= 0)
        {
            return;
        }
        if (nRows > numRows)
        {
            nRows = numRows;
        }
        if (nCols > numCols)
        {
            nCols = numCols;
        }
        nameCol -> printStartToEnd(0, nCols);
        cout << endl; // Đảm bảo xuống dòng sau khi in tiêu đề cột
        for (int i = 0; i < nRows; i++)
        {
            data -> get(i) -> printStartToEnd(0, nCols);
            if (i < nRows - 1) cout << endl;
        }
        // TODO: implement Task 2
    }
    void printTail(int nRows = 5, int nCols = 5) const
    {
        if (nRows <= 0 || nCols <= 0)
        {   
            return;
        }
        int numRows = data -> length();
        int numCols = nameCol -> length();
        if (data -> length() <= 0 || nameCol -> length() <= 0)
        {
            return;
        }
        if (nRows > numRows)
        {
            nRows = numRows;
        }
        if (nCols > numCols)
        {
            nCols = numCols;
        }
        int startRow = numRows - nRows;
        int startCol = numCols - nCols;
        nameCol -> printStartToEnd (startCol, numCols);
        cout << endl; // Đảm bảo xuống dòng sau khi in tiêu đề cột
        for (int i = startRow; i < numRows; i++)
        {
            data -> get(i) -> printStartToEnd(startCol, numCols);
            if (i < numRows - 1) cout << endl;
        }
    }
    bool drop(int axis = 0, int index = 0, std::string columns = "")
    {
        int sodong = data -> length();
        int socot = nameCol -> length();
        if (axis == 0)
        {
            if (index >= sodong || index < 0)
            {
                return false;
            }
            data -> remove(index);
            return true;
        }
        if (axis == 1)
        {
            int dem;
            for (dem = 0; dem < socot; dem ++)
            {
                if (nameCol -> get(dem) == columns)
                {
                    break;
                }
            }
            if (dem == socot)
            {
                return false;
            }
            else
            {
                nameCol -> remove(dem);
                for (int i = 0; i < sodong; i ++)
                {
                    data -> get(i) -> remove(dem);
                }
                return true;
            }
        }
        return false;
    }
    Dataset extract(int startRow = 0, int endRow = -1, int startCol = 0, int endCol = -1) const
    {
        // Tạo đối tượng Dataset mới để chứa dữ liệu trích xuất
        if (endRow > -1 && startRow > endRow || endCol > -1 && startCol > endCol)
        {
            throw std::out_of_range("get(): Out of range");
        }
        if (startRow < -1 || endRow < -1 || startCol < -1 || endCol < -1)
        {
            throw std::out_of_range("get(): Out of range");
        }
        Dataset extractedData;
        // Kiểm tra xem data có rỗng không
        if (data -> length() <= 0 || nameCol -> length() <= 0) 
        {
            // extractedData.nameCol = nullptr;
            // extractedData.data = nullptr;
            return extractedData; // Trả về Dataset rỗng
        }
        // Xác định số hàng và số cột cần trích xuất
        int numRows = data -> length();
        int numCols = nameCol -> length();

        // Xác định giá trị cuối cùng của endRow và endCol nếu chúng bằng -1
        if (endRow == -1) 
        {
            endRow = numRows - 1;
            //startRow = 0;
        }
        if (endCol == -1) 
        {
            endCol = numCols - 1;
            //startCol = 0;
        }
        // Giới hạn giá trị endRow và endCol
        if (endRow >= numRows)
        {
            endRow = numRows - 1;
        }
        if (endCol >= numCols)
        {
            endCol = numCols - 1;
        }
        if (startRow < numRows && startCol < numCols)
        {
            // Sao chép tên cột từ bảng dữ liệu gốc
            for (int i = startCol; i <= endCol; i++)
            {
                extractedData.nameCol -> push_back(nameCol -> get(i)); // Thêm tên cột vào bảng dữ liệu mới
            }

            // Duyệt qua các hàng và cột cần trích xuất từ bảng dữ liệu gốc
            for (int i = startRow; i <= endRow; i++)
            {
                List<int>* newRow = new Image<int>(); // Tạo một hàng mới
                for (int j = startCol; j <= endCol; j++)
                {
                    newRow -> push_back(data -> get(i) -> get(j)); // Thêm giá trị vào hàng mới
                }
                extractedData.data -> push_back(newRow); // Thêm hàng vào bảng dữ liệu mới
            }
        }
        return extractedData; // Trả về bảng dữ liệu đã trích xuất
    }

    double distanceEuclidean(const List<int> *x, const List<int> *y) const
    {
        int lengthX = x->length();
        int lengthY = y->length();
        int minLength = std::min(lengthX, lengthY);
    
        int* arrayX = new int[lengthX];
        int* arrayY = new int[lengthY];
        x->getArray(arrayX);
        y->getArray(arrayY);
    
        double distance = 0.0;
        for (int i = 0; i < minLength; i++) 
        {
            int diff = arrayX[i] - arrayY[i];
            distance += diff * diff;
        }
        for (int i = minLength; i < lengthX; i++) 
        {
            distance += arrayX[i] * arrayX[i];
        }
        for (int i = minLength; i < lengthY; i++) 
        {
            distance += arrayY[i] * arrayY[i];
        }
        delete[] arrayX;
        delete[] arrayY;
        return sqrt(distance);
    }

    Dataset predict(const Dataset &X_train, const Dataset &Y_train, const int k) const
    {
        Dataset y_pred;
        if(X_train.data->length() == 0 || Y_train.data->length() == 0) return y_pred ;
        y_pred.nameCol->push_back(Y_train.getnameCol()->get(0)); // Đảm bảo tên cột được sao chép chính xác

        int labelMax = 10; // Giả sử có tối đa 10 nhãn khác nhau, điều này cần được xác định từ dữ liệu
        int soluongdong_ypred = this->data->length();

        for (int i = 0; i < soluongdong_ypred; i++) {
            pair<double, int> *pairs = new pair<double, int>[X_train.getData()->length()];

            for (int j = 0; j < X_train.getData()->length(); j++) {
                pairs[j].first = distanceEuclidean(this->data->get(i), X_train.getData()->get(j));
                pairs[j].second = Y_train.getData()->get(j)->get(0);
            }

            // Sử dụng bubble sort
            // for (int m = 0; m < X_train.getData()->length() - 1; m++) {
            //     for (int n = 0; n < X_train.getData()->length() - m - 1; n++) {
            //         if (pairs[n].first > pairs[n + 1].first) {
            //             pair<double, int> temp = pairs[n];
            //             pairs[n] = pairs[n + 1];
            //             pairs[n + 1] = temp;
            //         }
            //     }
            // }

            // Sử dụng merge sort
            mergeSort(pairs, 0, X_train.getData()->length() - 1);

            // Cấp phát động cho mảng tần suất
            int* labelFrequency = new int[labelMax]{0};
            for (int p = 0; p < k && p < X_train.getData()->length(); p++) {
                if (pairs[p].second < labelMax) {
                    labelFrequency[pairs[p].second]++;
                }
            }

            // Tìm nhãn với tần suất cao nhất
            int maxFrequency = 0, mostFrequentLabel = -1;
            for (int l = 0; l < labelMax; l++) {
                if (labelFrequency[l] > maxFrequency) {
                    maxFrequency = labelFrequency[l];
                    mostFrequentLabel = l;
                }
            }

            List<int>* newRow = new Image<int>(); // Tạo một hàng mới với nhãn dự đoán
            newRow->push_back(mostFrequentLabel);
            y_pred.getData()->push_back(newRow);

            delete[] pairs; // Giải phóng bộ nhớ cho pairs
            delete[] labelFrequency; // Giải phóng bộ nhớ cho mảng tần suất
        }
        return y_pred;
    }

    double score(const Dataset &y_predict) const
    {
        // TODO: implement Task 3
        int soanhdung = 0;
        int soanh = y_predict.getData()->length();
        // Thêm kiểm tra để đảm bảo cả hai dataset có cùng kích thước
        if (soanh != this->data->length()) 
        {
            return -1;
        }
        if (soanh > 0)
        {
            for (int i = 0; i < soanh; i++)
            {
                if (y_predict.getData()->get(i)->get(0) == this->data->get(i)->get(0))
                {
                    soanhdung++;
                }
            }
            // Sửa lỗi chia số nguyên bằng cách ép kiểu ít nhất một số thành double
            return static_cast<double>(soanhdung) / static_cast<double>(soanh);
        }
        return -1;
    }
};

class kNN
{
private:
    int k;
    Dataset X_train;
    Dataset Y_train;
    // You may need to define more
public:
    kNN(int k = 5) : k(k){};
    void fit(const Dataset &X_train, const Dataset &y_train)
    {
        this->X_train = X_train;
        this->Y_train = y_train;
    }
    Dataset predict(const Dataset &X_test)
    {
        return X_test.predict(this->X_train, this->Y_train, this->k);
    }
    double score(const Dataset &y_test, const Dataset &y_pred)
    {
        return y_test.score(y_pred);
    }
};

void train_test_split(Dataset &X, Dataset &Y, double test_size,
                       Dataset &X_train, Dataset &X_test, Dataset &Y_train, Dataset &Y_test);
void merge(pair<double, int>* arr, int l, int m, int r);
void mergeSort(pair<double, int> arr[], int l, int r);