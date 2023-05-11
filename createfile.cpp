#include<iostream>
#include<vector>
#include<fstream>
#include<map>

using namespace std;

class student
{
    public:
    long long roll;
    int grno,isPresent;
    string name, Class, labBatch, classBatch;
    student()
    {
        roll=0;
        isPresent=0;
    }
};

map <long long int, student> students;

void addStudent(long long roll, string name, string Class, string labBatch)
{
    students[roll].name=name;
    students[roll].Class=Class;
    students[roll].labBatch=labBatch;
}


void createData()
{
    addStudent(92100103002,"JAY  SAVALIYA", "TC1", "A");
    addStudent(92100103003,"SOHIL VIJAYBHAI BHARWAD", "TC1", "A");
    addStudent(92100103004,"DHYEY VIPULKUMAR MAKWANA", "TC1", "A");
    addStudent(92100103005,"RIDHAM HARESH SAGTHIA", "TC1", "A");
    addStudent(92100103006,"DHRUV PRABHULAL FEFAR", "TC1", "A");
    addStudent(92100103007,"UTSAV JAYBHAI KHUNT", "TC1", "A");
    addStudent(92100103008,"RISHIT KAMLESH PABARI", "TC1", "A");
    addStudent(92100103009,"YASH NITESHBHAI KHUNT", "TC1", "A");
    addStudent(92100103010,"JAY RAJESHBHAI KHUNT", "TC1", "A");
    addStudent(92100103011,"TEJ DIPAK DEKIWADIYA", "TC1", "A");
    addStudent(92100103012,"JAYNIL JAYANTIBHAI SOLANKI", "TC1", "A");
    addStudent(92100103013,"DEVARSHI JIGNESH VISAVADIA", "TC1", "A");
    addStudent(92100103014,"DEEP SURESHKUMAR MAIYANI", "TC1", "A");
    addStudent(92100103015,"AELISH MAHESHBHAI NONGHANVADARA", "TC1", "A");
    addStudent(92100103016,"MANAV GHANSHYAMBHAI RASDIYA", "TC1", "A");
    addStudent(92100103017,"JASH CHIMAN LAL", "TC1", "A");
    addStudent(92100103018,"ARKESH ASHOKBHAI MOLIYA", "TC1", "A");
    addStudent(92100103020,"KHUSHI SANJAYBHAI BHALODI", "TC1", "A");
    addStudent(92100103021,"TIRTH KETANBHAI MARADIYA", "TC1", "A");
    addStudent(92100103022,"KARANKUMAR PRAKASHBHAI CHHATRALA", "TC1", "A");
    addStudent(92100103023,"PARAS HEMANT BHATT", "TC1", "A");
    addStudent(92100103026,"VIVEK AJITBHAI HARKHANI", "TC1", "A");
    addStudent(92100103027,"SAUMYA HITESH DELIWALA", "TC1", "A");
    addStudent(92100103028,"URVI PRAKASHBHAI PATEL", "TC1", "B");
    addStudent(92100103029,"DIYA RAJENDRAN NAIR", "TC1", "B");
    addStudent(92100103030,"KUNAL PANKAJBHAI GADHIA", "TC1", "B");
    addStudent(92100103031,"BRIJESHKUMAR LALITBHAI YADAV", "TC1", "B");
    addStudent(92100103032,"YASH DIGVIJAY SINGH", "TC1", "B");
    addStudent(92100103033,"RUTIKA DINESHBHAI GOHIL", "TC1", "B");
    addStudent(92100103034,"SOHAM ATULBHAI NAGPARA", "TC1", "B");
    addStudent(92100103035,"SUMIT SURESH BAGORA", "TC1", "B");
    addStudent(92100103036,"NIKHITA DIPAKBHAI MAHIDA", "TC1", "B");
    addStudent(92100103037,"VASU PRAMIT SAPARIYA", "TC1", "B");
    addStudent(92100103038,"VAIBHAV KIRTIBHAI SONI", "TC1", "B");
    addStudent(92100103039,"ARYAN KIRANKUMAR SONI", "TC1", "B");
    addStudent(92100103040,"TATHAGAT  CHANDRASEN", "TC1", "B");
    addStudent(92100103041,"SHIVRAJSINH VIDURSINH JADEJA", "TC1", "B");
    addStudent(92100103042,"PARTH ASITBHAI KAMOTHI", "TC1", "B");
    addStudent(92100103043,"DHAVAL MOHANBHAI BALAS", "TC1", "B");
    addStudent(92100103044,"VIVEK ASHVINBHAI VIRADIYA", "TC1", "B");
    addStudent(92100103045,"MISHA RAJIV VAISHNAV", "TC1", "B");
    addStudent(92100103046,"ABHI RAJUBHAI PATADIYA", "TC1", "B");
    addStudent(92100103047,"JINKALBEN KALPESHBHAI GADHIYA", "TC1", "B");
    addStudent(92100103048,"JAY YOGESHBHAI DEVMURARI", "TC1", "B");
    addStudent(92100103049,"VRUNDA NARANBHAI CHANDARANA", "TC1", "B");
    addStudent(92100103050,"KARAN ASHIVINBHAI LIMBASIYA", "TC1", "B");
    addStudent(92100103052,"SIDDHARTH MANUBHAI GARAIYA", "TC1", "C");
    addStudent(92100103053,"PARTHIVKUMAR HARESHBHAI SHEKHLIYA", "TC1", "C");
    addStudent(92100103054,"CHANDRESHKUMAR RAMESHBHAI PARMAR", "TC1", "C");
    addStudent(92100103055,"KRISHNA HITENDRAGIRI GOSWAMI", "TC1", "C");
    addStudent(92100103056,"DHRUV SANJAYBHAI SANKHAVARA", "TC1", "C");
    addStudent(92100103057,"PRINCE KAMLESHBHAI KORINGA", "TC1", "C");
    addStudent(92100103058,"PARAM JAYESHBHAI BHIMANI", "TC1", "C");
    addStudent(92100103059,"DEV HARMESH SANGHVI", "TC1", "C");
    addStudent(92100103060,"DHRUVKUMAR RAJESHBHAI GORIYA", "TC1", "C");
    addStudent(92100103061,"RONIK  MAKWANA", "TC1", "C");
    addStudent(92100103062,"JAY KANTILAL PATEL", "TC1", "C");
    addStudent(92100103063,"JIT HITESHKUMAR GOR", "TC1", "C");
    addStudent(92100103065,"SHUBHAM  OJHA", "TC1", "C");
    addStudent(92100103066,"VIRAT YOGESHBHAI JOBANPUTRA", "TC1", "C");
    addStudent(92100103068,"BHAVIT CHANDRARKBHAI MEHTA", "TC1", "C");
    addStudent(92100103069,"PARTHIL JAGDISHBHAI VEKARIYA", "TC1", "C");
    addStudent(92100103070,"HAMAS HUSSAIN JIVANI", "TC1", "C");
    addStudent(92100103071,"NIR VINODBHAI VACHHANI", "TC1", "C");
    addStudent(92100103072,"ANMOL  BUDHWANI", "TC1", "C");
    addStudent(92100103073,"GUNJAN JENTIBHAI SIDDHAPURA", "TC1", "C");
    addStudent(92100103076,"ALIM EBADULLAH MOLLICK", "TC1", "C");
    addStudent(92100103077,"MILANBHAI VINODBHAI MAKVANA", "TC1", "C");
    addStudent(92100103078,"PALLAVI MANI  TRIPATHI", "TC1", "C");
    addStudent(92100103333,"YASH JITENDRA GOTRIJIYA", "TC1", "C");
}
void exportStudentData()
{
    ofstream f("studentDatabase.txt");
    for (auto i : students)
        f<<i.first<<"\n"<<i.second.name<<"\n"<<i.second.Class<<"\n"<<i.second.labBatch<<"\n";
    f.close();
}
void importStudentData()
{
    ifstream f("studentDatabase.txt");
    while (f)
    {
        student s;
        f>>s.roll;
        f.ignore();
        getline(f,s.name);
        f>>s.grno;
        f.ignore();
        getline(f,s.Class);
        getline(f,s.labBatch);
        if (s.roll)
            students[s.roll]=s;
    }
    cout<<students.size()<<" Students Added Sucessfully";
    f.close();
}
int main()
{
    createData();
    exportStudentData();
    importStudentData();
    return 0;
}
