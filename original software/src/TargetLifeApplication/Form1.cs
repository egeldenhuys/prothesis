using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.IO;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.Windows.Forms;
using System.Xml;

namespace TargetLifeApplication
{
	public class Form1 : Form
	{
		private const int RGBMAX = 255;

		private UserInfo userInfo = default(UserInfo);

		private string fname = "user.info";

		private string[] categories = new string[]
		{
			"Roles",
			"Skills",
			"People Orientation",
			"Priorities"
		};

		private bool loadedCareers;

		private bool genMAnalysis;

		private bool genCAnalysis;

		private ArrayList roles = new ArrayList();

		private ArrayList skills = new ArrayList();

		private ArrayList people = new ArrayList();

		private ArrayList priorities = new ArrayList();

		private ArrayList careers = new ArrayList();

		private ArrayList mbti = new ArrayList();

		private ArrayList other = new ArrayList();

		private IContainer components;

		private Label lblCopyright;

		private TextBox txtCName;

		private TextBox txtCSurname;

		private DateTimePicker dtpCDate;

		private DateTimePicker dtpMDate;

		private TextBox txtMName;

		private TextBox txtMSurname;

		private GroupBox groupBox16;

		private DateTimePicker dtpDate;

		private Button btnMColour1;

		private Button btnMColour2;

		private Button btnMColour3;

		private Button btnMColour4;

		private Button btnCColour4;

		private Button btnCColour3;

		private Button btnCColour2;

		private Button btnCColour1;

		private Timer tmrAutoSave;

		private TextBox txtWork4;

		private TextBox txtWork3;

		private TextBox txtWork2;

		private TextBox txtWork1;

		private TextBox txtWordList;

		private TextBox txtPeople4;

		private TextBox txtPeople3;

		private TextBox txtPeople2;

		private TextBox txtPeople1;

		private TextBox txtDream2;

		private TextBox txtDream1;

		private TextBox txtDream3;

		private TextBox txtPassion5;

		private TextBox txtPassion4;

		private TextBox txtPassion3;

		private TextBox txtPassion2;

		private TextBox txtPassion1;

		private TextBox txtCTheme4;

		private TextBox txtCTheme3;

		private TextBox txtCTheme2;

		private TextBox txtCTheme1;

		private TabPage tpMAnalysis;

		private TabPage tpCAnalysis;

		private Button button12;

		private Button btnClear;

		private TextBox txtColourC;

		private Button button7;

		private Panel panel2;

		private TextBox txtColour;

		private GroupBox grpPriorities;

		private GroupBox grpPeopleC;

		private GroupBox grpWork;

		private GroupBox grpKeysC;

		private GroupBox grpSkillsC;

		private GroupBox grpRolesC;

		private TextBox txtMBTI2c;

		private TextBox txtMBTI3c;

		private TextBox txtMBTI1c;

		private TextBox txtMBTI4c;

		private Label lblC23;

		private Label lblC3;

		private Label lblC2;

		private Label lblC4b;

		private Label lblC4;

		private Label lblC1b;

		private Label lblC1;

		private GroupBox grpWords;

		private GroupBox grpPeople;

		private GroupBox grpPassions;

		private GroupBox grpDreams;

		private TextBox txtRecommendation;

		private GroupBox groupBox29;

		private GroupBox groupBox28;

		private GroupBox groupBox27;

		private Label lblM4b;

		private Label lblM23b;

		private Label lblM1b;

		private Label lblM4;

		private Label lblM3;

		private Label lblM2;

		private Label lblM1;

		private GroupBox groupBox24;

		private GroupBox groupBox4;

		private GroupBox groupBox5;

		private GroupBox groupBox15;

		private GroupBox groupBox14;

		private GroupBox groupBox13;

		private GroupBox groupBox12;

		private GroupBox groupBox7;

		private GroupBox groupBox17;

		private TextBox txtMTheme4;

		private TextBox txtMTheme3;

		private TextBox txtMTheme2;

		private TextBox txtMTheme1;

		private GroupBox grpKeys;

		private GroupBox grpSkills;

		private GroupBox grpRoles;

		private TextBox txtMBTI1;

		private TextBox txtMBTI2;

		private TextBox txtMBTI3;

		private TextBox txtMBTI4;

		private TabControl tabMission;

		private TabControl tabCareer;

		private ListBox listBox1;

		private GroupBox groupBox3;

		private GroupBox groupBox8;

		private GroupBox groupBox9;

		private GroupBox groupBox10;

		private GroupBox groupBox11;

		private GroupBox groupBox6;

		private CheckedListBox clbPriorities;

		private CheckedListBox clbPeople;

		private Label label24;

		private Label label23;

		private Label label22;

		private Label label21;

		private Label label19;

		private TextBox txtWork;

		private TabPage tabPage13;

		private TabPage tabPage12;

		private TabPage tabPage11;

		private TextBox txtPassions;

		private Label label16;

		private Label label17;

		private Label label18;

		private TextBox txtWords;

		private Label label11;

		private Label label12;

		private Label label13;

		private Label label14;

		private Label label15;

		private TextBox txtPeople;

		private Label label9;

		private Label label10;

		private TextBox txtDreams;

		private Label label6;

		private Label label7;

		private Label label8;

		private TabPage tabPage10;

		private TabPage tabPage9;

		private TabPage tabPage8;

		private Label label1;

		private Label label2;

		private Label label3;

		private Label label4;

		private Label label5;

		private TabPage tabPage7;

		private CheckedListBox clbSkills;

		private CheckedListBox clbRoles;

		private TabPage tabPage6;

		private TabPage tabPage5;

		private Label lblDescription;

		private GroupBox groupBox1;

		private GroupBox groupBox2;

		private PictureBox logo;

		private TabPage tabPage4;

		private TabPage tabPage3;

		private TabControl tabControl1;

		private TabPage tabPage1;

		private TextBox txtLifeKey3;

		private TextBox txtLifeKey2;

		private TextBox txtLifeKey1;

		private TextBox txtKey4;

		private TextBox txtKey3;

		private TextBox txtKey2;

		private TextBox txtKey1;

		private TextBox txtSurname;

		private TextBox txtName;

		private Button button1;

		private Panel panel1;

		private Button button6;

		private ColorDialog colorDialog1;

		private Button btnNext;

		public Form1()
		{
			this.InitializeComponent();
			this.btnCColour1.BackColor = this.btnMColour1.BackColor;
			this.btnCColour2.BackColor = this.btnMColour2.BackColor;
			this.btnCColour3.BackColor = this.btnMColour3.BackColor;
			this.btnCColour4.BackColor = this.btnMColour4.BackColor;
		}

		private bool LoadInfo()
		{
			if (File.Exists(this.fname))
			{
				FileStream fileStream = new FileStream(this.fname, FileMode.Open);
				BinaryFormatter binaryFormatter = new BinaryFormatter();
				try
				{
					this.userInfo = (UserInfo)binaryFormatter.Deserialize(fileStream);
				}
				catch (SerializationException)
				{
					throw;
				}
				finally
				{
					fileStream.Close();
				}
				this.GetMBTIData();
				this.GetMissionData();
				this.GetCareerData();
				return true;
			}
			return false;
		}

		private void button1_Click(object sender, EventArgs e)
		{
			if (File.Exists(this.fname))
			{
				if (File.Exists(this.fname + ".bak"))
				{
					File.Delete(this.fname + ".bak");
					File.Copy(this.fname, this.fname + ".bak");
				}
				else
				{
					File.Copy(this.fname, this.fname + ".bak");
				}
			}
			this.SetMBTIData();
			this.SetMissionData();
			this.SetCareerData();
			this.SetMissionAnalysisData();
			this.SetCareerAnalysisData();
			FileStream fileStream = new FileStream(this.fname, FileMode.Create);
			BinaryFormatter binaryFormatter = new BinaryFormatter();
			try
			{
				binaryFormatter.Serialize(fileStream, this.userInfo);
			}
			catch (SerializationException)
			{
				throw;
			}
			finally
			{
				fileStream.Close();
			}
		}

		private void LoadXML(string fileName, bool career = false)
		{
			if (!File.Exists(fileName))
			{
				return;
			}
			XmlTextReader xmlTextReader = new XmlTextReader(fileName);
			int num = -1;
			LoadXMLInfo loadXMLInfo = default(LoadXMLInfo);
			if (string.Compare(fileName, "Roles.xml", true) == 0)
			{
				num = 0;
			}
			if (string.Compare(fileName, "Skills.xml", true) == 0)
			{
				num = 1;
			}
			if (string.Compare(fileName, "People.xml", true) == 0)
			{
				num = 2;
			}
			if (string.Compare(fileName, "Priorities.xml", true) == 0)
			{
				num = 3;
			}
			if (career)
			{
				num = 4;
			}
			if (string.Compare(fileName, "MBTI.xml", true) == 0)
			{
				num = 5;
			}
			xmlTextReader.Read();
			while (!xmlTextReader.EOF)
			{
				xmlTextReader.Read();
				if (xmlTextReader.HasAttributes)
				{
					if (xmlTextReader.AttributeCount > 1)
					{
						loadXMLInfo.name = xmlTextReader.GetAttribute(0);
						loadXMLInfo.description = xmlTextReader.GetAttribute(1);
						switch (num)
						{
						case 0:
							this.roles.Add(loadXMLInfo);
							break;
						case 1:
							this.skills.Add(loadXMLInfo);
							break;
						case 2:
							this.people.Add(loadXMLInfo);
							break;
						case 3:
							this.priorities.Add(loadXMLInfo);
							break;
						case 4:
							this.careers.Add(loadXMLInfo);
							break;
						default:
							this.other.Add(loadXMLInfo);
							break;
						}
					}
					else
					{
						loadXMLInfo.name = xmlTextReader.GetAttribute(0);
						loadXMLInfo.description = "Not available";
						switch (num)
						{
						case 0:
							this.roles.Add(loadXMLInfo);
							break;
						case 1:
							this.skills.Add(loadXMLInfo);
							break;
						case 2:
							this.people.Add(loadXMLInfo);
							break;
						case 3:
							this.priorities.Add(loadXMLInfo);
							break;
						case 4:
							this.careers.Add(loadXMLInfo);
							break;
						default:
							this.other.Add(loadXMLInfo);
							break;
						}
					}
				}
				if (xmlTextReader.HasValue && xmlTextReader.NodeType != XmlNodeType.Whitespace)
				{
					loadXMLInfo.value = xmlTextReader.Value;
					if (num == 5)
					{
						this.mbti.Add(loadXMLInfo);
					}
					else
					{
						this.other.Add(loadXMLInfo);
					}
				}
			}
		}

		private void InitializeUserInfo()
		{
			this.userInfo.mbti = default(Mbti);
			this.userInfo.mbti.lifeKeys = new string[3];
			this.userInfo.mission = default(Mission);
			this.userInfo.mission.roles = new string[7];
			this.userInfo.mission.skills = new string[7];
			this.userInfo.mission.passions = new string[5];
			this.userInfo.mission.dreams = new string[3];
			this.userInfo.mission.people = new string[4];
			this.userInfo.career = default(Career);
			this.userInfo.career.peopleOrientation = new string[14];
			this.userInfo.career.priorities = new string[4];
			this.userInfo.career.workEnvironment = new string[4];
			this.userInfo.missionAnalysis = default(Analysis);
			this.userInfo.missionAnalysis.colourLifeKeys = new Color[3];
			this.userInfo.missionAnalysis.colourRoles = new Color[7];
			this.userInfo.missionAnalysis.colourSkills = new Color[7];
			this.userInfo.careerAnalysis = default(Analysis);
			this.userInfo.careerAnalysis.colourLifeKeys = new Color[3];
			this.userInfo.careerAnalysis.colourRoles = new Color[7];
			this.userInfo.careerAnalysis.colourSkills = new Color[7];
			this.userInfo.careerAnalysis.colourPeopleC = new Color[16];
			this.userInfo.careerAnalysis.colourPriorities = new Color[4];
		}

		private void SetMBTIData()
		{
			this.userInfo.mbti.name = this.txtName.Text;
			this.userInfo.mbti.surname = this.txtSurname.Text;
			this.userInfo.mbti.mbti = string.Concat(new string[]
			{
				this.txtKey1.Text,
				",",
				this.txtKey2.Text,
				",",
				this.txtKey3.Text,
				",",
				this.txtKey4.Text
			});
			this.userInfo.mbti.date = this.dtpDate.Value;
			this.userInfo.mbti.lifeKeys[0] = this.txtLifeKey1.Text;
			this.userInfo.mbti.lifeKeys[1] = this.txtLifeKey2.Text;
			this.userInfo.mbti.lifeKeys[2] = this.txtLifeKey3.Text;
		}

		private void GetMBTIData()
		{
			this.txtName.Text = this.userInfo.mbti.name;
			this.txtSurname.Text = this.userInfo.mbti.surname;
			this.dtpDate.Value = this.userInfo.mbti.date;
			string[] array = this.userInfo.mbti.mbti.Split(new char[]
			{
				','
			});
			this.txtKey1.Text = array[0];
			this.txtKey2.Text = array[1];
			this.txtKey3.Text = array[2];
			this.txtKey4.Text = array[3];
			this.txtLifeKey1.Text = this.userInfo.mbti.lifeKeys[0];
			this.txtLifeKey2.Text = this.userInfo.mbti.lifeKeys[1];
			this.txtLifeKey3.Text = this.userInfo.mbti.lifeKeys[2];
		}

		private void GetCheckedItems(CheckedListBox clb, string[] strArr)
		{
			int num = 0;
			foreach (object current in clb.CheckedItems)
			{
				strArr[num] = current.ToString();
				num++;
			}
		}

		private void SetCheckedItems(CheckedListBox clb, string[] strArr)
		{
			for (int i = 0; i < strArr.Length; i++)
			{
				string text = strArr[i];
				if (text == null)
				{
					return;
				}
				foreach (object current in clb.Items)
				{
					if (string.Compare(clb.GetItemText(current), text) == 0)
					{
						clb.SetItemCheckState(clb.Items.IndexOf(current), CheckState.Checked);
						break;
					}
				}
			}
		}

		private void SetMissionData()
		{
			this.GetCheckedItems(this.clbRoles, this.userInfo.mission.roles);
			this.GetCheckedItems(this.clbSkills, this.userInfo.mission.skills);
			this.userInfo.mission.passions[0] = this.txtPassion1.Text;
			this.userInfo.mission.passions[1] = this.txtPassion2.Text;
			this.userInfo.mission.passions[2] = this.txtPassion3.Text;
			this.userInfo.mission.passions[3] = this.txtPassion4.Text;
			this.userInfo.mission.passions[4] = this.txtPassion5.Text;
			this.userInfo.mission.summaryPassions = this.txtPassions.Text;
			this.userInfo.mission.dreams[0] = this.txtDream1.Text;
			this.userInfo.mission.dreams[1] = this.txtDream2.Text;
			this.userInfo.mission.dreams[2] = this.txtDream3.Text;
			this.userInfo.mission.summaryDreams = this.txtDreams.Text;
			this.userInfo.mission.people[0] = this.txtPeople1.Text;
			this.userInfo.mission.people[1] = this.txtPeople2.Text;
			this.userInfo.mission.people[2] = this.txtPeople3.Text;
			this.userInfo.mission.people[3] = this.txtPeople4.Text;
			this.userInfo.mission.summaryPeople = this.txtPeople.Text;
			this.userInfo.mission.words = this.txtWordList.Lines;
			this.userInfo.mission.summaryWords = this.txtWords.Text;
		}

		private void GetMissionData()
		{
			this.SetCheckedItems(this.clbRoles, this.userInfo.mission.roles);
			this.SetCheckedItems(this.clbSkills, this.userInfo.mission.skills);
			this.txtPassion1.Text = this.userInfo.mission.passions[0];
			this.txtPassion2.Text = this.userInfo.mission.passions[1];
			this.txtPassion3.Text = this.userInfo.mission.passions[2];
			this.txtPassion4.Text = this.userInfo.mission.passions[3];
			this.txtPassion5.Text = this.userInfo.mission.passions[4];
			this.txtPassions.Text = this.userInfo.mission.summaryPassions;
			this.txtDream1.Text = this.userInfo.mission.dreams[0];
			this.txtDream2.Text = this.userInfo.mission.dreams[1];
			this.txtDream3.Text = this.userInfo.mission.dreams[2];
			this.txtDreams.Text = this.userInfo.mission.summaryDreams;
			this.txtPeople1.Text = this.userInfo.mission.people[0];
			this.txtPeople2.Text = this.userInfo.mission.people[1];
			this.txtPeople3.Text = this.userInfo.mission.people[2];
			this.txtPeople4.Text = this.userInfo.mission.people[3];
			this.txtPeople.Text = this.userInfo.mission.summaryPeople;
			this.txtWordList.Lines = this.userInfo.mission.words;
			this.txtWords.Text = this.userInfo.mission.summaryWords;
		}

		private void SetCareerData()
		{
			this.GetCheckedItems(this.clbPeople, this.userInfo.career.peopleOrientation);
			this.GetCheckedItems(this.clbPriorities, this.userInfo.career.priorities);
			this.userInfo.career.workEnvironment[0] = this.txtWork1.Text;
			this.userInfo.career.workEnvironment[1] = this.txtWork2.Text;
			this.userInfo.career.workEnvironment[2] = this.txtWork3.Text;
			this.userInfo.career.workEnvironment[3] = this.txtWork4.Text;
			this.userInfo.career.summaryWorkEnvironemnt = this.txtWork.Text;
		}

		private void GetCareerData()
		{
			this.SetCheckedItems(this.clbPeople, this.userInfo.career.peopleOrientation);
			this.SetCheckedItems(this.clbPriorities, this.userInfo.career.priorities);
			this.txtWork1.Text = this.userInfo.career.workEnvironment[0];
			this.txtWork2.Text = this.userInfo.career.workEnvironment[1];
			this.txtWork3.Text = this.userInfo.career.workEnvironment[2];
			this.txtWork4.Text = this.userInfo.career.workEnvironment[3];
			this.txtWork.Text = this.userInfo.career.summaryWorkEnvironemnt;
		}

		private void SaveControlColours(Color[] c, Control.ControlCollection cc)
		{
			int num = 0;
			for (int i = 0; i < c.Length; i++)
			{
				Color arg_14_0 = c[i];
				num++;
			}
			for (int j = 0; j < cc.Count; j++)
			{
				c[j] = cc[j].BackColor;
			}
		}

		private void LoadControlColours(Color[] c, Control.ControlCollection cc)
		{
			if (c == null)
			{
				MessageBox.Show("Err");
			}
			int num = 0;
			for (int i = 0; i < c.Length; i++)
			{
				Color arg_22_0 = c[i];
				num++;
			}
			for (int j = 0; j < cc.Count; j++)
			{
				cc[j].BackColor = c[j];
			}
		}

		private void SetMissionAnalysisData()
		{
			if (this.genMAnalysis)
			{
				try
				{
					this.userInfo.missionAnalysis.colourLifeKeys[2] = this.grpKeys.Controls[0].BackColor;
					this.userInfo.missionAnalysis.colourLifeKeys[1] = this.grpKeys.Controls[1].BackColor;
					this.userInfo.missionAnalysis.colourLifeKeys[0] = this.grpKeys.Controls[2].BackColor;
					this.SaveControlColours(this.userInfo.missionAnalysis.colourRoles, this.grpRoles.Controls);
					this.SaveControlColours(this.userInfo.missionAnalysis.colourSkills, this.grpSkills.Controls);
					this.userInfo.missionAnalysis.theme1 = this.txtMTheme1.Text;
					this.userInfo.careerAnalysis.theme1 = this.userInfo.missionAnalysis.theme1;
					this.userInfo.missionAnalysis.colour1 = this.txtMTheme1.BackColor;
					this.userInfo.missionAnalysis.theme2 = this.txtMTheme2.Text;
					this.userInfo.careerAnalysis.theme2 = this.userInfo.missionAnalysis.theme2;
					this.userInfo.missionAnalysis.colour2 = this.txtMTheme2.BackColor;
					this.userInfo.missionAnalysis.theme3 = this.txtMTheme3.Text;
					this.userInfo.careerAnalysis.theme3 = this.userInfo.missionAnalysis.theme3;
					this.userInfo.missionAnalysis.colour3 = this.txtMTheme3.BackColor;
					this.userInfo.missionAnalysis.theme4 = this.txtMTheme4.Text;
					this.userInfo.careerAnalysis.theme4 = this.userInfo.missionAnalysis.theme4;
					this.userInfo.missionAnalysis.colour4 = this.txtMTheme4.BackColor;
					this.userInfo.missionAnalysis.colourDreams = this.grpDreams.Controls[0].BackColor;
					this.userInfo.missionAnalysis.colourPassions = this.grpPassions.Controls[0].BackColor;
					this.userInfo.missionAnalysis.colourPeople = this.grpPeople.Controls[0].BackColor;
					this.userInfo.missionAnalysis.colourWords = this.grpWords.Controls[0].BackColor;
				}
				catch (Exception)
				{
				}
			}
		}

		private void GetMissionAnalysisData()
		{
			if (this.genMAnalysis)
			{
				try
				{
					if (this.userInfo.missionAnalysis.colourLifeKeys != null)
					{
						this.grpKeys.Controls[0].BackColor = this.userInfo.missionAnalysis.colourLifeKeys[2];
						this.grpKeys.Controls[1].BackColor = this.userInfo.missionAnalysis.colourLifeKeys[1];
						this.grpKeys.Controls[2].BackColor = this.userInfo.missionAnalysis.colourLifeKeys[0];
					}
					this.LoadControlColours(this.userInfo.missionAnalysis.colourRoles, this.grpRoles.Controls);
					this.LoadControlColours(this.userInfo.missionAnalysis.colourSkills, this.grpSkills.Controls);
					this.txtMTheme1.Text = this.userInfo.missionAnalysis.theme1;
					this.txtMTheme1.BackColor = this.userInfo.missionAnalysis.colour1;
					this.txtMTheme2.Text = this.userInfo.missionAnalysis.theme2;
					this.txtMTheme2.BackColor = this.userInfo.missionAnalysis.colour2;
					this.txtMTheme3.Text = this.userInfo.missionAnalysis.theme3;
					this.txtMTheme3.BackColor = this.userInfo.missionAnalysis.colour3;
					this.txtMTheme4.Text = this.userInfo.missionAnalysis.theme4;
					this.txtMTheme4.BackColor = this.userInfo.missionAnalysis.colour4;
					this.grpDreams.Controls[0].BackColor = this.userInfo.missionAnalysis.colourDreams;
					this.grpPassions.Controls[0].BackColor = this.userInfo.missionAnalysis.colourPassions;
					this.grpPeople.Controls[0].BackColor = this.userInfo.missionAnalysis.colourPeople;
					this.grpWords.Controls[0].BackColor = this.userInfo.missionAnalysis.colourWords;
				}
				catch (Exception)
				{
				}
			}
		}

		private void SetCareerAnalysisData()
		{
			if (this.genCAnalysis)
			{
				this.userInfo.careerAnalysis.colourLifeKeys[2] = this.grpKeysC.Controls[0].BackColor;
				this.userInfo.careerAnalysis.colourLifeKeys[1] = this.grpKeysC.Controls[1].BackColor;
				this.userInfo.careerAnalysis.colourLifeKeys[0] = this.grpKeysC.Controls[2].BackColor;
				this.SaveControlColours(this.userInfo.careerAnalysis.colourRoles, this.grpRolesC.Controls);
				this.SaveControlColours(this.userInfo.careerAnalysis.colourSkills, this.grpSkillsC.Controls);
				this.userInfo.careerAnalysis.theme1 = this.userInfo.missionAnalysis.theme1;
				this.userInfo.careerAnalysis.colour1 = this.txtCTheme1.BackColor;
				this.userInfo.careerAnalysis.theme2 = this.userInfo.missionAnalysis.theme2;
				this.userInfo.careerAnalysis.colour2 = this.txtCTheme2.BackColor;
				this.userInfo.careerAnalysis.theme3 = this.userInfo.missionAnalysis.theme3;
				this.userInfo.careerAnalysis.colour3 = this.txtCTheme3.BackColor;
				this.userInfo.careerAnalysis.theme4 = this.userInfo.missionAnalysis.theme4;
				this.userInfo.careerAnalysis.colour4 = this.txtCTheme4.BackColor;
				this.userInfo.careerAnalysis.recommendation = this.txtRecommendation.Text;
				this.userInfo.careerAnalysis.colourWork = this.grpWork.Controls[0].BackColor;
				this.SaveControlColours(this.userInfo.careerAnalysis.colourPeopleC, this.grpPeopleC.Controls);
				this.SaveControlColours(this.userInfo.careerAnalysis.colourPriorities, this.grpPriorities.Controls);
			}
		}

		private void GetCareerAnalysisData()
		{
			if (this.genCAnalysis)
			{
				try
				{
					if (this.userInfo.careerAnalysis.colourLifeKeys != null)
					{
						this.grpKeysC.Controls[0].BackColor = this.userInfo.careerAnalysis.colourLifeKeys[2];
						this.grpKeysC.Controls[1].BackColor = this.userInfo.careerAnalysis.colourLifeKeys[1];
						this.grpKeysC.Controls[2].BackColor = this.userInfo.careerAnalysis.colourLifeKeys[0];
					}
					this.LoadControlColours(this.userInfo.careerAnalysis.colourRoles, this.grpRolesC.Controls);
					this.LoadControlColours(this.userInfo.careerAnalysis.colourSkills, this.grpSkillsC.Controls);
					this.txtCTheme1.Text = this.userInfo.careerAnalysis.theme1;
					this.txtCTheme1.BackColor = this.userInfo.careerAnalysis.colour1;
					this.txtCTheme2.Text = this.userInfo.careerAnalysis.theme2;
					this.txtCTheme2.BackColor = this.userInfo.careerAnalysis.colour2;
					this.txtCTheme3.Text = this.userInfo.careerAnalysis.theme3;
					this.txtCTheme3.BackColor = this.userInfo.careerAnalysis.colour3;
					this.txtCTheme4.Text = this.userInfo.careerAnalysis.theme4;
					this.txtCTheme4.BackColor = this.userInfo.careerAnalysis.colour4;
					this.txtRecommendation.Text = this.userInfo.careerAnalysis.recommendation;
					this.grpWork.Controls[0].BackColor = this.userInfo.careerAnalysis.colourWork;
					this.LoadControlColours(this.userInfo.careerAnalysis.colourPeopleC, this.grpPeopleC.Controls);
					this.LoadControlColours(this.userInfo.careerAnalysis.colourPriorities, this.grpPriorities.Controls);
				}
				catch (Exception)
				{
				}
			}
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			this.logo.BringToFront();
			this.lblCopyright.BringToFront();
			this.LoadXML("Roles.xml", false);
			foreach (LoadXMLInfo loadXMLInfo in this.roles)
			{
				this.clbRoles.Items.Add(loadXMLInfo.name);
			}
			this.LoadXML("Skills.xml", false);
			foreach (LoadXMLInfo loadXMLInfo2 in this.skills)
			{
				this.clbSkills.Items.Add(loadXMLInfo2.name);
			}
			this.LoadXML("People.xml", false);
			foreach (LoadXMLInfo loadXMLInfo3 in this.people)
			{
				this.clbPeople.Items.Add(loadXMLInfo3.name);
			}
			this.LoadXML("Priorities.xml", false);
			foreach (LoadXMLInfo loadXMLInfo4 in this.priorities)
			{
				this.clbPriorities.Items.Add(loadXMLInfo4.name);
			}
			this.LoadXML("MBTI.xml", false);
			this.InitializeUserInfo();
			this.LoadInfo();
		}

		private void Form1_Shown(object sender, EventArgs e)
		{
			if (string.Compare(this.txtName.Text, "Name") == 0)
			{
				this.txtName.Focus();
			}
		}

		private void TabControl1SelectedIndexChanged(object sender, EventArgs e)
		{
			if (this.genMAnalysis)
			{
				this.SetMissionAnalysisData();
			}
			if (this.genCAnalysis && this.genMAnalysis)
			{
				this.SetCareerAnalysisData();
			}
			if (string.Compare(this.tabControl1.SelectedTab.Text, "Mission") == 0)
			{
				this.lblDescription.Parent = this.tabMission.TabPages[0];
			}
			if (this.tabControl1.SelectedTab.Text.Contains("Career"))
			{
				this.lblDescription.Parent = this.tabCareer.TabPages[0];
				if (!this.loadedCareers)
				{
					this.listBox1.Items.Clear();
					string text = string.Concat(new string[]
					{
						"careers\\",
						this.txtKey1.Text,
						this.txtKey2.Text,
						this.txtKey3.Text,
						this.txtKey4.Text,
						".xml"
					});
					text = text.ToLower();
					if (!text.Contains("abcd"))
					{
						this.careers.Clear();
						this.LoadXML(text, true);
						this.listBox1.Items.Clear();
						foreach (LoadXMLInfo loadXMLInfo in this.careers)
						{
							this.listBox1.Items.Add(loadXMLInfo.name);
						}
						this.loadedCareers = true;
					}
					else
					{
						this.listBox1.Items.Clear();
						this.listBox1.Items.Add("MBTI Incomplete");
					}
				}
				if (this.tabCareer.SelectedTab.Text.Contains("Analysis"))
				{
					this.GenerateCareerData();
					this.TabControl2SelectedIndexChanged(this.tabCareer, new EventArgs());
				}
			}
		}

		private void Form1FormClosing(object sender, FormClosingEventArgs e)
		{
			this.button1_Click(sender, e);
		}

		private void CheckedListBox1SelectedIndexChanged(object sender, EventArgs e)
		{
			CheckedListBox checkedListBox = (CheckedListBox)sender;
			LoadXMLInfo loadXMLInfo = default(LoadXMLInfo);
			if (string.Compare(checkedListBox.Name, "clbRoles") == 0)
			{
				loadXMLInfo = (LoadXMLInfo)this.roles[checkedListBox.SelectedIndex];
			}
			if (string.Compare(checkedListBox.Name, "clbSkills") == 0)
			{
				loadXMLInfo = (LoadXMLInfo)this.skills[checkedListBox.SelectedIndex];
			}
			if (string.Compare(checkedListBox.Name, "clbPeople") == 0)
			{
				loadXMLInfo = (LoadXMLInfo)this.people[checkedListBox.SelectedIndex];
			}
			if (string.Compare(checkedListBox.Name, "clbPriorities") == 0)
			{
				loadXMLInfo = (LoadXMLInfo)this.priorities[checkedListBox.SelectedIndex];
			}
			this.lblDescription.Text = loadXMLInfo.description;
		}

		private TextBox DynamicTextBox(string text, DockStyle dockstyle, bool multiLine = false)
		{
			TextBox textBox = new TextBox();
			textBox.Text = text;
			textBox.ReadOnly = true;
			textBox.BackColor = this.btnClear.BackColor;
			textBox.Multiline = multiLine;
			textBox.Dock = dockstyle;
			textBox.Click += new EventHandler(this.TxtColourClick);
			textBox.KeyDown += new KeyEventHandler(this.TxtColourKeyDown);
			return textBox;
		}

		private void GenerateCareerData()
		{
			this.grpRolesC.Controls.Clear();
			this.grpSkillsC.Controls.Clear();
			this.grpKeysC.Controls.Clear();
			this.grpPeopleC.Controls.Clear();
			this.grpWork.Controls.Clear();
			this.grpPriorities.Controls.Clear();
			this.txtMBTI1c.Text = this.txtKey1.Text;
			this.txtMBTI2c.Text = this.txtKey2.Text;
			this.txtMBTI3c.Text = this.txtKey3.Text;
			this.txtMBTI4c.Text = this.txtKey4.Text;
			foreach (object current in this.clbRoles.CheckedItems)
			{
				this.grpRolesC.Controls.Add(this.DynamicTextBox(current.ToString(), DockStyle.Bottom, false));
			}
			foreach (object current2 in this.clbSkills.CheckedItems)
			{
				this.grpSkillsC.Controls.Add(this.DynamicTextBox(current2.ToString(), DockStyle.Bottom, false));
			}
			this.grpKeysC.Controls.Add(this.DynamicTextBox(this.txtLifeKey3.Text, DockStyle.Top, false));
			this.grpKeysC.Controls.Add(this.DynamicTextBox(this.txtLifeKey2.Text, DockStyle.Top, false));
			this.grpKeysC.Controls.Add(this.DynamicTextBox(this.txtLifeKey1.Text, DockStyle.Top, false));
			foreach (LoadXMLInfo loadXMLInfo in this.mbti)
			{
				if (string.Compare(loadXMLInfo.name, this.txtKey1.Text) == 0)
				{
					if (this.lblC1.Text.Contains("label"))
					{
						this.lblC1.Text = loadXMLInfo.value;
					}
					else
					{
						this.lblC1b.Text = loadXMLInfo.value;
					}
				}
				if (string.Compare(loadXMLInfo.name, this.txtKey2.Text) == 0)
				{
					this.lblC2.Text = loadXMLInfo.value;
				}
				if (string.Compare(loadXMLInfo.name, this.txtKey3.Text) == 0)
				{
					this.lblC3.Text = loadXMLInfo.value;
				}
				if (string.Compare(loadXMLInfo.name, this.txtKey4.Text) == 0)
				{
					if (this.lblC4.Text.Contains("label"))
					{
						this.lblC4.Text = loadXMLInfo.value;
					}
					else
					{
						this.lblC4b.Text = loadXMLInfo.value;
					}
				}
				if (string.Compare(loadXMLInfo.name, this.txtKey2.Text + this.txtKey3.Text) == 0)
				{
					this.lblC23.Text = loadXMLInfo.value;
				}
			}
			foreach (object current3 in this.clbPeople.CheckedItems)
			{
				this.grpPeopleC.Controls.Add(this.DynamicTextBox(current3.ToString(), DockStyle.Bottom, false));
			}
			foreach (object current4 in this.clbPriorities.CheckedItems)
			{
				this.grpPriorities.Controls.Add(this.DynamicTextBox(current4.ToString(), DockStyle.Bottom, false));
			}
			this.grpWork.Controls.Add(this.DynamicTextBox(this.txtWork.Text, DockStyle.Fill, true));
			this.genCAnalysis = true;
		}

		private void TabControl2SelectedIndexChanged(object sender, EventArgs e)
		{
			this.lblDescription.Text = "";
			TabControl tabControl = (TabControl)sender;
			string[] array = this.categories;
			for (int i = 0; i < array.Length; i++)
			{
				string strB = array[i];
				if (string.Compare(tabControl.SelectedTab.Text, strB) == 0)
				{
					this.lblDescription.Parent = tabControl.SelectedTab;
					break;
				}
			}
			this.tmrAutoSave.Enabled = false;
			if (string.Compare(tabControl.Name, "tabMission") == 0 && string.Compare(tabControl.SelectedTab.Text, "Analysis") == 0)
			{
				this.grpRoles.Controls.Clear();
				this.grpKeys.Controls.Clear();
				this.grpSkills.Controls.Clear();
				this.grpWords.Controls.Clear();
				this.grpPeople.Controls.Clear();
				this.grpDreams.Controls.Clear();
				this.grpPassions.Controls.Clear();
				this.txtMBTI1.Text = this.txtKey1.Text;
				this.txtMBTI2.Text = this.txtKey2.Text;
				this.txtMBTI3.Text = this.txtKey3.Text;
				this.txtMBTI4.Text = this.txtKey4.Text;
				this.txtCTheme1.Text = this.txtMTheme1.Text;
				this.txtCTheme2.Text = this.txtMTheme2.Text;
				this.txtCTheme3.Text = this.txtMTheme3.Text;
				this.txtCTheme4.Text = this.txtMTheme4.Text;
				foreach (object current in this.clbRoles.CheckedItems)
				{
					this.grpRoles.Controls.Add(this.DynamicTextBox(current.ToString(), DockStyle.Bottom, false));
				}
				foreach (object current2 in this.clbSkills.CheckedItems)
				{
					this.grpSkills.Controls.Add(this.DynamicTextBox(current2.ToString(), DockStyle.Bottom, false));
				}
				this.grpKeys.Controls.Add(this.DynamicTextBox(this.txtLifeKey3.Text, DockStyle.Top, false));
				this.grpKeys.Controls.Add(this.DynamicTextBox(this.txtLifeKey2.Text, DockStyle.Top, false));
				this.grpKeys.Controls.Add(this.DynamicTextBox(this.txtLifeKey1.Text, DockStyle.Top, false));
				foreach (LoadXMLInfo loadXMLInfo in this.mbti)
				{
					if (string.Compare(loadXMLInfo.name, this.txtKey1.Text) == 0)
					{
						if (this.lblM1.Text.Contains("label"))
						{
							this.lblM1.Text = loadXMLInfo.value;
						}
						else
						{
							this.lblM1b.Text = loadXMLInfo.value;
						}
					}
					if (string.Compare(loadXMLInfo.name, this.txtKey2.Text) == 0)
					{
						this.lblM2.Text = loadXMLInfo.value;
					}
					if (string.Compare(loadXMLInfo.name, this.txtKey3.Text) == 0)
					{
						this.lblM3.Text = loadXMLInfo.value;
					}
					if (string.Compare(loadXMLInfo.name, this.txtKey4.Text) == 0)
					{
						if (this.lblM4.Text.Contains("label"))
						{
							this.lblM4.Text = loadXMLInfo.value;
						}
						else
						{
							this.lblM4b.Text = loadXMLInfo.value;
						}
					}
					if (string.Compare(loadXMLInfo.name, this.txtKey2.Text + this.txtKey3.Text) == 0)
					{
						this.lblM23b.Text = loadXMLInfo.value;
					}
				}
				this.grpPassions.Controls.Add(this.DynamicTextBox(this.txtPassions.Text, DockStyle.Fill, true));
				this.grpPeople.Controls.Add(this.DynamicTextBox(this.txtPeople.Text, DockStyle.Fill, true));
				this.grpDreams.Controls.Add(this.DynamicTextBox(this.txtDreams.Text, DockStyle.Fill, true));
				this.grpWords.Controls.Add(this.DynamicTextBox(this.txtWords.Text, DockStyle.Fill, true));
				this.genMAnalysis = true;
			}
			if (string.Compare(tabControl.Name, "tabCareer") == 0 && string.Compare(tabControl.SelectedTab.Text, "Analysis") == 0)
			{
				this.GenerateCareerData();
			}
			this.GetMissionAnalysisData();
			this.GetCareerAnalysisData();
			this.tmrAutoSave.Enabled = true;
		}

		private void ClbRolesItemCheck(object sender, ItemCheckEventArgs e)
		{
			CheckedListBox checkedListBox = (CheckedListBox)sender;
			if (e.NewValue == CheckState.Checked && checkedListBox.CheckedItems.Count == 7)
			{
				MessageBox.Show("Select only 7");
				e.NewValue = CheckState.Unchecked;
			}
		}

		private void ClbPrioritiesItemCheck(object sender, ItemCheckEventArgs e)
		{
			CheckedListBox checkedListBox = sender as CheckedListBox;
			if (e.NewValue == CheckState.Checked && checkedListBox.CheckedItems.Count == 4)
			{
				MessageBox.Show("Select only 4");
				e.NewValue = CheckState.Unchecked;
			}
		}

		private void TxtKeyTextChanged(object sender, EventArgs e)
		{
			this.loadedCareers = false;
		}

		private void ColourClick(object sender, EventArgs e)
		{
			Button button = (Button)sender;
			this.txtColour.BackColor = button.BackColor;
		}

		private Color InvertAColour(Color ColourToInvert)
		{
			return Color.FromArgb((int)(255 - ColourToInvert.R), (int)(255 - ColourToInvert.G), (int)(255 - ColourToInvert.B));
		}

		private void TxtColourClick(object sender, EventArgs e)
		{
			TextBox textBox = (TextBox)sender;
			textBox.BackColor = this.txtColour.BackColor;
			if (textBox.BackColor.Name.Contains("Blue"))
			{
				textBox.ForeColor = this.InvertAColour(this.txtColour.BackColor);
			}
		}

		private void TxtColourKeyDown(object sender, KeyEventArgs e)
		{
			e.SuppressKeyPress = true;
		}

		private void TxtColourBackColorChanged(object sender, EventArgs e)
		{
			TextBox textBox = (TextBox)sender;
			this.txtColourC.BackColor = textBox.BackColor;
		}

		private void TmrAutoSaveTick(object sender, EventArgs e)
		{
			this.button1_Click(sender, e);
		}

		private void DtpDateValueChanged(object sender, EventArgs e)
		{
			DateTimePicker dateTimePicker = (DateTimePicker)sender;
			this.dtpMDate.Value = dateTimePicker.Value;
			this.dtpCDate.Value = dateTimePicker.Value;
		}

		private void TxtNameTextChanged(object sender, EventArgs e)
		{
			TextBox textBox = (TextBox)sender;
			this.txtMName.Text = textBox.Text;
			this.txtCName.Text = textBox.Text;
		}

		private void TxtSurnameTextChanged(object sender, EventArgs e)
		{
			TextBox textBox = (TextBox)sender;
			this.txtMSurname.Text = textBox.Text;
			this.txtCSurname.Text = textBox.Text;
		}

		protected override void Dispose(bool disposing)
		{
			if (disposing && this.components != null)
			{
				this.components.Dispose();
			}
			base.Dispose(disposing);
		}

		private void InitializeComponent()
		{
			this.components = new Container();
			ComponentResourceManager componentResourceManager = new ComponentResourceManager(typeof(Form1));
			this.tabControl1 = new TabControl();
			this.tabPage1 = new TabPage();
			this.dtpDate = new DateTimePicker();
			this.groupBox16 = new GroupBox();
			this.txtSurname = new TextBox();
			this.txtName = new TextBox();
			this.groupBox2 = new GroupBox();
			this.txtKey1 = new TextBox();
			this.txtKey2 = new TextBox();
			this.txtKey3 = new TextBox();
			this.txtKey4 = new TextBox();
			this.groupBox1 = new GroupBox();
			this.txtLifeKey1 = new TextBox();
			this.txtLifeKey2 = new TextBox();
			this.txtLifeKey3 = new TextBox();
			this.btnNext = new Button();
			this.button1 = new Button();
			this.tabPage3 = new TabPage();
			this.tabMission = new TabControl();
			this.tabPage5 = new TabPage();
			this.clbRoles = new CheckedListBox();
			this.lblDescription = new Label();
			this.tabPage6 = new TabPage();
			this.clbSkills = new CheckedListBox();
			this.tabPage7 = new TabPage();
			this.txtPassions = new TextBox();
			this.label8 = new Label();
			this.txtPassion5 = new TextBox();
			this.label5 = new Label();
			this.txtPassion4 = new TextBox();
			this.label4 = new Label();
			this.txtPassion3 = new TextBox();
			this.label3 = new Label();
			this.txtPassion2 = new TextBox();
			this.label2 = new Label();
			this.txtPassion1 = new TextBox();
			this.label1 = new Label();
			this.tabPage8 = new TabPage();
			this.txtDreams = new TextBox();
			this.label10 = new Label();
			this.txtDream3 = new TextBox();
			this.label9 = new Label();
			this.txtDream2 = new TextBox();
			this.label7 = new Label();
			this.txtDream1 = new TextBox();
			this.label6 = new Label();
			this.tabPage9 = new TabPage();
			this.txtPeople = new TextBox();
			this.label15 = new Label();
			this.txtPeople4 = new TextBox();
			this.label14 = new Label();
			this.txtPeople3 = new TextBox();
			this.label13 = new Label();
			this.txtPeople2 = new TextBox();
			this.label12 = new Label();
			this.txtPeople1 = new TextBox();
			this.label11 = new Label();
			this.tabPage10 = new TabPage();
			this.txtWords = new TextBox();
			this.label18 = new Label();
			this.txtWordList = new TextBox();
			this.label17 = new Label();
			this.label16 = new Label();
			this.tpMAnalysis = new TabPage();
			this.grpWords = new GroupBox();
			this.grpPeople = new GroupBox();
			this.grpPassions = new GroupBox();
			this.grpDreams = new GroupBox();
			this.groupBox6 = new GroupBox();
			this.groupBox11 = new GroupBox();
			this.txtMTheme4 = new TextBox();
			this.groupBox10 = new GroupBox();
			this.txtMTheme3 = new TextBox();
			this.groupBox9 = new GroupBox();
			this.txtMTheme2 = new TextBox();
			this.groupBox8 = new GroupBox();
			this.txtMTheme1 = new TextBox();
			this.grpKeys = new GroupBox();
			this.grpSkills = new GroupBox();
			this.grpRoles = new GroupBox();
			this.groupBox3 = new GroupBox();
			this.groupBox27 = new GroupBox();
			this.lblM23b = new Label();
			this.lblM3 = new Label();
			this.lblM2 = new Label();
			this.txtMBTI2 = new TextBox();
			this.txtMBTI3 = new TextBox();
			this.lblM4b = new Label();
			this.lblM4 = new Label();
			this.lblM1b = new Label();
			this.lblM1 = new Label();
			this.txtMBTI1 = new TextBox();
			this.txtMBTI4 = new TextBox();
			this.panel1 = new Panel();
			this.dtpMDate = new DateTimePicker();
			this.txtMSurname = new TextBox();
			this.txtMName = new TextBox();
			this.btnClear = new Button();
			this.txtColour = new TextBox();
			this.button6 = new Button();
			this.btnMColour4 = new Button();
			this.btnMColour3 = new Button();
			this.btnMColour2 = new Button();
			this.btnMColour1 = new Button();
			this.tabPage4 = new TabPage();
			this.tabCareer = new TabControl();
			this.tabPage11 = new TabPage();
			this.clbPeople = new CheckedListBox();
			this.tabPage12 = new TabPage();
			this.clbPriorities = new CheckedListBox();
			this.tabPage13 = new TabPage();
			this.txtWork = new TextBox();
			this.label19 = new Label();
			this.txtWork4 = new TextBox();
			this.label21 = new Label();
			this.txtWork3 = new TextBox();
			this.label22 = new Label();
			this.txtWork2 = new TextBox();
			this.label23 = new Label();
			this.txtWork1 = new TextBox();
			this.label24 = new Label();
			this.tpCAnalysis = new TabPage();
			this.panel2 = new Panel();
			this.dtpCDate = new DateTimePicker();
			this.txtCSurname = new TextBox();
			this.txtCName = new TextBox();
			this.button12 = new Button();
			this.txtColourC = new TextBox();
			this.button7 = new Button();
			this.btnCColour4 = new Button();
			this.btnCColour3 = new Button();
			this.btnCColour2 = new Button();
			this.btnCColour1 = new Button();
			this.groupBox5 = new GroupBox();
			this.listBox1 = new ListBox();
			this.groupBox29 = new GroupBox();
			this.txtRecommendation = new TextBox();
			this.groupBox4 = new GroupBox();
			this.groupBox28 = new GroupBox();
			this.lblC23 = new Label();
			this.lblC3 = new Label();
			this.lblC2 = new Label();
			this.txtMBTI2c = new TextBox();
			this.txtMBTI3c = new TextBox();
			this.lblC4b = new Label();
			this.lblC4 = new Label();
			this.lblC1b = new Label();
			this.lblC1 = new Label();
			this.txtMBTI1c = new TextBox();
			this.txtMBTI4c = new TextBox();
			this.grpWork = new GroupBox();
			this.grpKeysC = new GroupBox();
			this.grpSkillsC = new GroupBox();
			this.grpRolesC = new GroupBox();
			this.grpPriorities = new GroupBox();
			this.groupBox17 = new GroupBox();
			this.groupBox7 = new GroupBox();
			this.groupBox12 = new GroupBox();
			this.txtCTheme4 = new TextBox();
			this.groupBox13 = new GroupBox();
			this.txtCTheme3 = new TextBox();
			this.groupBox14 = new GroupBox();
			this.txtCTheme2 = new TextBox();
			this.groupBox15 = new GroupBox();
			this.txtCTheme1 = new TextBox();
			this.grpPeopleC = new GroupBox();
			this.groupBox24 = new GroupBox();
			this.colorDialog1 = new ColorDialog();
			this.logo = new PictureBox();
			this.tmrAutoSave = new Timer(this.components);
			this.lblCopyright = new Label();
			this.tabControl1.SuspendLayout();
			this.tabPage1.SuspendLayout();
			this.groupBox16.SuspendLayout();
			this.groupBox2.SuspendLayout();
			this.groupBox1.SuspendLayout();
			this.tabPage3.SuspendLayout();
			this.tabMission.SuspendLayout();
			this.tabPage5.SuspendLayout();
			this.tabPage6.SuspendLayout();
			this.tabPage7.SuspendLayout();
			this.tabPage8.SuspendLayout();
			this.tabPage9.SuspendLayout();
			this.tabPage10.SuspendLayout();
			this.tpMAnalysis.SuspendLayout();
			this.groupBox6.SuspendLayout();
			this.groupBox11.SuspendLayout();
			this.groupBox10.SuspendLayout();
			this.groupBox9.SuspendLayout();
			this.groupBox8.SuspendLayout();
			this.groupBox3.SuspendLayout();
			this.groupBox27.SuspendLayout();
			this.panel1.SuspendLayout();
			this.tabPage4.SuspendLayout();
			this.tabCareer.SuspendLayout();
			this.tabPage11.SuspendLayout();
			this.tabPage12.SuspendLayout();
			this.tabPage13.SuspendLayout();
			this.tpCAnalysis.SuspendLayout();
			this.panel2.SuspendLayout();
			this.groupBox5.SuspendLayout();
			this.groupBox29.SuspendLayout();
			this.groupBox4.SuspendLayout();
			this.groupBox28.SuspendLayout();
			this.grpPriorities.SuspendLayout();
			this.groupBox7.SuspendLayout();
			this.groupBox12.SuspendLayout();
			this.groupBox13.SuspendLayout();
			this.groupBox14.SuspendLayout();
			this.groupBox15.SuspendLayout();
			((ISupportInitialize)this.logo).BeginInit();
			base.SuspendLayout();
			this.tabControl1.Controls.Add(this.tabPage1);
			this.tabControl1.Controls.Add(this.tabPage3);
			this.tabControl1.Controls.Add(this.tabPage4);
			this.tabControl1.Dock = DockStyle.Fill;
			this.tabControl1.Location = new Point(0, 0);
			this.tabControl1.Name = "tabControl1";
			this.tabControl1.SelectedIndex = 0;
			this.tabControl1.Size = new Size(1008, 562);
			this.tabControl1.TabIndex = 0;
			this.tabControl1.SelectedIndexChanged += new EventHandler(this.TabControl1SelectedIndexChanged);
			this.tabPage1.Controls.Add(this.dtpDate);
			this.tabPage1.Controls.Add(this.groupBox16);
			this.tabPage1.Controls.Add(this.groupBox2);
			this.tabPage1.Controls.Add(this.groupBox1);
			this.tabPage1.Controls.Add(this.btnNext);
			this.tabPage1.Controls.Add(this.button1);
			this.tabPage1.Location = new Point(4, 22);
			this.tabPage1.Name = "tabPage1";
			this.tabPage1.Padding = new Padding(3);
			this.tabPage1.Size = new Size(1000, 536);
			this.tabPage1.TabIndex = 0;
			this.tabPage1.Tag = "0";
			this.tabPage1.Text = "Start";
			this.tabPage1.UseVisualStyleBackColor = true;
			this.dtpDate.Location = new Point(377, 57);
			this.dtpDate.Name = "dtpDate";
			this.dtpDate.Size = new Size(159, 20);
			this.dtpDate.TabIndex = 12;
			this.dtpDate.ValueChanged += new EventHandler(this.DtpDateValueChanged);
			this.groupBox16.Controls.Add(this.txtSurname);
			this.groupBox16.Controls.Add(this.txtName);
			this.groupBox16.Location = new Point(57, 38);
			this.groupBox16.Name = "groupBox16";
			this.groupBox16.Size = new Size(273, 48);
			this.groupBox16.TabIndex = 11;
			this.groupBox16.TabStop = false;
			this.groupBox16.Text = "Name";
			this.txtSurname.Location = new Point(132, 19);
			this.txtSurname.Name = "txtSurname";
			this.txtSurname.Size = new Size(133, 20);
			this.txtSurname.TabIndex = 3;
			this.txtSurname.Text = "Surname";
			this.txtSurname.TextChanged += new EventHandler(this.TxtSurnameTextChanged);
			this.txtName.Location = new Point(6, 19);
			this.txtName.Name = "txtName";
			this.txtName.Size = new Size(121, 20);
			this.txtName.TabIndex = 2;
			this.txtName.Text = "Name";
			this.txtName.TextChanged += new EventHandler(this.TxtNameTextChanged);
			this.groupBox2.Controls.Add(this.txtKey1);
			this.groupBox2.Controls.Add(this.txtKey2);
			this.groupBox2.Controls.Add(this.txtKey3);
			this.groupBox2.Controls.Add(this.txtKey4);
			this.groupBox2.Location = new Point(57, 92);
			this.groupBox2.Name = "groupBox2";
			this.groupBox2.Size = new Size(145, 42);
			this.groupBox2.TabIndex = 2;
			this.groupBox2.TabStop = false;
			this.groupBox2.Text = "MBTI";
			this.txtKey1.Location = new Point(6, 16);
			this.txtKey1.MaxLength = 1;
			this.txtKey1.Name = "txtKey1";
			this.txtKey1.Size = new Size(25, 20);
			this.txtKey1.TabIndex = 0;
			this.txtKey1.Text = "A";
			this.txtKey1.TextChanged += new EventHandler(this.TxtKeyTextChanged);
			this.txtKey2.Location = new Point(39, 16);
			this.txtKey2.MaxLength = 1;
			this.txtKey2.Name = "txtKey2";
			this.txtKey2.Size = new Size(25, 20);
			this.txtKey2.TabIndex = 1;
			this.txtKey2.Text = "B";
			this.txtKey2.TextChanged += new EventHandler(this.TxtKeyTextChanged);
			this.txtKey3.Location = new Point(69, 16);
			this.txtKey3.MaxLength = 1;
			this.txtKey3.Name = "txtKey3";
			this.txtKey3.Size = new Size(25, 20);
			this.txtKey3.TabIndex = 2;
			this.txtKey3.Text = "C";
			this.txtKey3.TextChanged += new EventHandler(this.TxtKeyTextChanged);
			this.txtKey4.Location = new Point(102, 16);
			this.txtKey4.MaxLength = 1;
			this.txtKey4.Name = "txtKey4";
			this.txtKey4.Size = new Size(25, 20);
			this.txtKey4.TabIndex = 3;
			this.txtKey4.Text = "D";
			this.txtKey4.TextChanged += new EventHandler(this.TxtKeyTextChanged);
			this.groupBox1.Controls.Add(this.txtLifeKey1);
			this.groupBox1.Controls.Add(this.txtLifeKey2);
			this.groupBox1.Controls.Add(this.txtLifeKey3);
			this.groupBox1.Location = new Point(57, 140);
			this.groupBox1.Name = "groupBox1";
			this.groupBox1.Size = new Size(273, 105);
			this.groupBox1.TabIndex = 3;
			this.groupBox1.TabStop = false;
			this.groupBox1.Text = "Life Keys";
			this.txtLifeKey1.Location = new Point(6, 19);
			this.txtLifeKey1.Name = "txtLifeKey1";
			this.txtLifeKey1.Size = new Size(259, 20);
			this.txtLifeKey1.TabIndex = 0;
			this.txtLifeKey1.Text = "Attribute 1";
			this.txtLifeKey2.Location = new Point(6, 45);
			this.txtLifeKey2.Name = "txtLifeKey2";
			this.txtLifeKey2.Size = new Size(259, 20);
			this.txtLifeKey2.TabIndex = 1;
			this.txtLifeKey2.Text = "Attribute 2";
			this.txtLifeKey3.Location = new Point(6, 71);
			this.txtLifeKey3.Name = "txtLifeKey3";
			this.txtLifeKey3.Size = new Size(259, 20);
			this.txtLifeKey3.TabIndex = 2;
			this.txtLifeKey3.Text = "Attribute 3";
			this.btnNext.Location = new Point(377, 317);
			this.btnNext.Name = "btnNext";
			this.btnNext.Size = new Size(75, 23);
			this.btnNext.TabIndex = 4;
			this.btnNext.Text = "Next ->";
			this.btnNext.UseVisualStyleBackColor = true;
			this.btnNext.Visible = false;
			this.button1.Location = new Point(57, 317);
			this.button1.Name = "button1";
			this.button1.Size = new Size(75, 23);
			this.button1.TabIndex = 10;
			this.button1.Text = "button1";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Visible = false;
			this.button1.Click += new EventHandler(this.button1_Click);
			this.tabPage3.Controls.Add(this.tabMission);
			this.tabPage3.Location = new Point(4, 22);
			this.tabPage3.Name = "tabPage3";
			this.tabPage3.Size = new Size(1000, 536);
			this.tabPage3.TabIndex = 2;
			this.tabPage3.Text = "Mission";
			this.tabPage3.UseVisualStyleBackColor = true;
			this.tabMission.Controls.Add(this.tabPage5);
			this.tabMission.Controls.Add(this.tabPage6);
			this.tabMission.Controls.Add(this.tabPage7);
			this.tabMission.Controls.Add(this.tabPage8);
			this.tabMission.Controls.Add(this.tabPage9);
			this.tabMission.Controls.Add(this.tabPage10);
			this.tabMission.Controls.Add(this.tpMAnalysis);
			this.tabMission.Dock = DockStyle.Fill;
			this.tabMission.Location = new Point(0, 0);
			this.tabMission.Name = "tabMission";
			this.tabMission.SelectedIndex = 0;
			this.tabMission.Size = new Size(1000, 536);
			this.tabMission.TabIndex = 0;
			this.tabMission.SelectedIndexChanged += new EventHandler(this.TabControl2SelectedIndexChanged);
			this.tabPage5.Controls.Add(this.clbRoles);
			this.tabPage5.Controls.Add(this.lblDescription);
			this.tabPage5.Location = new Point(4, 22);
			this.tabPage5.Name = "tabPage5";
			this.tabPage5.Padding = new Padding(3);
			this.tabPage5.Size = new Size(992, 510);
			this.tabPage5.TabIndex = 0;
			this.tabPage5.Text = "7 Roles";
			this.tabPage5.UseVisualStyleBackColor = true;
			this.clbRoles.Dock = DockStyle.Fill;
			this.clbRoles.FormattingEnabled = true;
			this.clbRoles.Location = new Point(3, 3);
			this.clbRoles.MultiColumn = true;
			this.clbRoles.Name = "clbRoles";
			this.clbRoles.Size = new Size(986, 474);
			this.clbRoles.TabIndex = 0;
			this.clbRoles.ItemCheck += new ItemCheckEventHandler(this.ClbRolesItemCheck);
			this.clbRoles.SelectedIndexChanged += new EventHandler(this.CheckedListBox1SelectedIndexChanged);
			this.lblDescription.Dock = DockStyle.Bottom;
			this.lblDescription.Location = new Point(3, 477);
			this.lblDescription.Name = "lblDescription";
			this.lblDescription.Size = new Size(986, 30);
			this.lblDescription.TabIndex = 6;
			this.tabPage6.Controls.Add(this.clbSkills);
			this.tabPage6.Location = new Point(4, 22);
			this.tabPage6.Name = "tabPage6";
			this.tabPage6.Padding = new Padding(3);
			this.tabPage6.Size = new Size(992, 510);
			this.tabPage6.TabIndex = 1;
			this.tabPage6.Text = "7 Skills";
			this.tabPage6.UseVisualStyleBackColor = true;
			this.clbSkills.Dock = DockStyle.Fill;
			this.clbSkills.FormattingEnabled = true;
			this.clbSkills.Location = new Point(3, 3);
			this.clbSkills.MultiColumn = true;
			this.clbSkills.Name = "clbSkills";
			this.clbSkills.Size = new Size(986, 504);
			this.clbSkills.TabIndex = 3;
			this.clbSkills.ItemCheck += new ItemCheckEventHandler(this.ClbRolesItemCheck);
			this.clbSkills.SelectedIndexChanged += new EventHandler(this.CheckedListBox1SelectedIndexChanged);
			this.tabPage7.Controls.Add(this.txtPassions);
			this.tabPage7.Controls.Add(this.label8);
			this.tabPage7.Controls.Add(this.txtPassion5);
			this.tabPage7.Controls.Add(this.label5);
			this.tabPage7.Controls.Add(this.txtPassion4);
			this.tabPage7.Controls.Add(this.label4);
			this.tabPage7.Controls.Add(this.txtPassion3);
			this.tabPage7.Controls.Add(this.label3);
			this.tabPage7.Controls.Add(this.txtPassion2);
			this.tabPage7.Controls.Add(this.label2);
			this.tabPage7.Controls.Add(this.txtPassion1);
			this.tabPage7.Controls.Add(this.label1);
			this.tabPage7.Location = new Point(4, 22);
			this.tabPage7.Name = "tabPage7";
			this.tabPage7.Size = new Size(992, 510);
			this.tabPage7.TabIndex = 2;
			this.tabPage7.Text = "Passions";
			this.tabPage7.UseVisualStyleBackColor = true;
			this.txtPassions.Dock = DockStyle.Top;
			this.txtPassions.Location = new Point(0, 238);
			this.txtPassions.Multiline = true;
			this.txtPassions.Name = "txtPassions";
			this.txtPassions.Size = new Size(992, 80);
			this.txtPassions.TabIndex = 11;
			this.label8.Dock = DockStyle.Top;
			this.label8.Location = new Point(0, 215);
			this.label8.Name = "label8";
			this.label8.Size = new Size(992, 23);
			this.label8.TabIndex = 10;
			this.label8.Text = "Now summarize the central themes from your answers and type them below:";
			this.txtPassion5.Dock = DockStyle.Top;
			this.txtPassion5.Location = new Point(0, 195);
			this.txtPassion5.Name = "txtPassion5";
			this.txtPassion5.Size = new Size(992, 20);
			this.txtPassion5.TabIndex = 9;
			this.label5.Dock = DockStyle.Top;
			this.label5.Location = new Point(0, 172);
			this.label5.Name = "label5";
			this.label5.Size = new Size(992, 23);
			this.label5.TabIndex = 4;
			this.label5.Text = "Is there something that you would have difficulty giving up? What is it and why?";
			this.txtPassion4.Dock = DockStyle.Top;
			this.txtPassion4.Location = new Point(0, 152);
			this.txtPassion4.Name = "txtPassion4";
			this.txtPassion4.Size = new Size(992, 20);
			this.txtPassion4.TabIndex = 8;
			this.label4.Dock = DockStyle.Top;
			this.label4.Location = new Point(0, 129);
			this.label4.Name = "label4";
			this.label4.Size = new Size(992, 23);
			this.label4.TabIndex = 3;
			this.label4.Text = "What thing that you do makes you really come alive?";
			this.txtPassion3.Dock = DockStyle.Top;
			this.txtPassion3.Location = new Point(0, 109);
			this.txtPassion3.Name = "txtPassion3";
			this.txtPassion3.Size = new Size(992, 20);
			this.txtPassion3.TabIndex = 7;
			this.label3.Dock = DockStyle.Top;
			this.label3.Location = new Point(0, 86);
			this.label3.Name = "label3";
			this.label3.Size = new Size(992, 23);
			this.label3.TabIndex = 2;
			this.label3.Text = "What would you like to change if you knew you couldn't fail?";
			this.txtPassion2.Dock = DockStyle.Top;
			this.txtPassion2.Location = new Point(0, 66);
			this.txtPassion2.Name = "txtPassion2";
			this.txtPassion2.Size = new Size(992, 20);
			this.txtPassion2.TabIndex = 6;
			this.label2.Dock = DockStyle.Top;
			this.label2.Location = new Point(0, 43);
			this.label2.Name = "label2";
			this.label2.Size = new Size(992, 23);
			this.label2.TabIndex = 1;
			this.label2.Text = "If you had one thing left to do and no limit on your resources, what would it be?";
			this.txtPassion1.Dock = DockStyle.Top;
			this.txtPassion1.Location = new Point(0, 23);
			this.txtPassion1.Name = "txtPassion1";
			this.txtPassion1.Size = new Size(992, 20);
			this.txtPassion1.TabIndex = 5;
			this.label1.Dock = DockStyle.Top;
			this.label1.Location = new Point(0, 0);
			this.label1.Name = "label1";
			this.label1.Size = new Size(992, 23);
			this.label1.TabIndex = 0;
			this.label1.Text = "What scene in a movie provoked strong emotional feelings, passion in your heart?";
			this.tabPage8.Controls.Add(this.txtDreams);
			this.tabPage8.Controls.Add(this.label10);
			this.tabPage8.Controls.Add(this.txtDream3);
			this.tabPage8.Controls.Add(this.label9);
			this.tabPage8.Controls.Add(this.txtDream2);
			this.tabPage8.Controls.Add(this.label7);
			this.tabPage8.Controls.Add(this.txtDream1);
			this.tabPage8.Controls.Add(this.label6);
			this.tabPage8.Location = new Point(4, 22);
			this.tabPage8.Name = "tabPage8";
			this.tabPage8.Size = new Size(992, 510);
			this.tabPage8.TabIndex = 3;
			this.tabPage8.Text = "Dreams";
			this.tabPage8.UseVisualStyleBackColor = true;
			this.txtDreams.Dock = DockStyle.Top;
			this.txtDreams.Location = new Point(0, 152);
			this.txtDreams.Multiline = true;
			this.txtDreams.Name = "txtDreams";
			this.txtDreams.Size = new Size(992, 80);
			this.txtDreams.TabIndex = 12;
			this.label10.Dock = DockStyle.Top;
			this.label10.Location = new Point(0, 129);
			this.label10.Name = "label10";
			this.label10.Size = new Size(992, 23);
			this.label10.TabIndex = 11;
			this.label10.Text = "Now summarize the central themes from your answers and type them below:";
			this.txtDream3.Dock = DockStyle.Top;
			this.txtDream3.Location = new Point(0, 109);
			this.txtDream3.Name = "txtDream3";
			this.txtDream3.Size = new Size(992, 20);
			this.txtDream3.TabIndex = 5;
			this.label9.Dock = DockStyle.Top;
			this.label9.Location = new Point(0, 86);
			this.label9.Name = "label9";
			this.label9.Size = new Size(992, 23);
			this.label9.TabIndex = 4;
			this.label9.Text = "What dreams do you have for your life at the moment?";
			this.txtDream2.Dock = DockStyle.Top;
			this.txtDream2.Location = new Point(0, 66);
			this.txtDream2.Name = "txtDream2";
			this.txtDream2.Size = new Size(992, 20);
			this.txtDream2.TabIndex = 3;
			this.label7.Dock = DockStyle.Top;
			this.label7.Location = new Point(0, 43);
			this.label7.Name = "label7";
			this.label7.Size = new Size(992, 23);
			this.label7.TabIndex = 2;
			this.label7.Text = "What dreams did you have for your life as a child? Is it still of meaning today?";
			this.txtDream1.Dock = DockStyle.Top;
			this.txtDream1.Location = new Point(0, 23);
			this.txtDream1.Name = "txtDream1";
			this.txtDream1.Size = new Size(992, 20);
			this.txtDream1.TabIndex = 1;
			this.label6.Dock = DockStyle.Top;
			this.label6.Location = new Point(0, 0);
			this.label6.Name = "label6";
			this.label6.Size = new Size(992, 23);
			this.label6.TabIndex = 0;
			this.label6.Text = "What was your favorite passtime as a child?";
			this.tabPage9.Controls.Add(this.txtPeople);
			this.tabPage9.Controls.Add(this.label15);
			this.tabPage9.Controls.Add(this.txtPeople4);
			this.tabPage9.Controls.Add(this.label14);
			this.tabPage9.Controls.Add(this.txtPeople3);
			this.tabPage9.Controls.Add(this.label13);
			this.tabPage9.Controls.Add(this.txtPeople2);
			this.tabPage9.Controls.Add(this.label12);
			this.tabPage9.Controls.Add(this.txtPeople1);
			this.tabPage9.Controls.Add(this.label11);
			this.tabPage9.Location = new Point(4, 22);
			this.tabPage9.Name = "tabPage9";
			this.tabPage9.Size = new Size(992, 510);
			this.tabPage9.TabIndex = 4;
			this.tabPage9.Text = "People ID";
			this.tabPage9.UseVisualStyleBackColor = true;
			this.txtPeople.Dock = DockStyle.Top;
			this.txtPeople.Location = new Point(0, 275);
			this.txtPeople.Multiline = true;
			this.txtPeople.Name = "txtPeople";
			this.txtPeople.Size = new Size(992, 80);
			this.txtPeople.TabIndex = 13;
			this.label15.Dock = DockStyle.Top;
			this.label15.Location = new Point(0, 252);
			this.label15.Name = "label15";
			this.label15.Size = new Size(992, 23);
			this.label15.TabIndex = 12;
			this.label15.Text = "Now summarize the central themes from your answers and type them below:";
			this.txtPeople4.Dock = DockStyle.Top;
			this.txtPeople4.Location = new Point(0, 212);
			this.txtPeople4.Multiline = true;
			this.txtPeople4.Name = "txtPeople4";
			this.txtPeople4.Size = new Size(992, 40);
			this.txtPeople4.TabIndex = 7;
			this.label14.Dock = DockStyle.Top;
			this.label14.Location = new Point(0, 189);
			this.label14.Name = "label14";
			this.label14.Size = new Size(992, 23);
			this.label14.TabIndex = 6;
			this.label14.Text = "With which character in a movie or a book did you relate to the most in your life? Why?";
			this.txtPeople3.Dock = DockStyle.Top;
			this.txtPeople3.Location = new Point(0, 149);
			this.txtPeople3.Multiline = true;
			this.txtPeople3.Name = "txtPeople3";
			this.txtPeople3.Size = new Size(992, 40);
			this.txtPeople3.TabIndex = 5;
			this.label13.Dock = DockStyle.Top;
			this.label13.Location = new Point(0, 126);
			this.label13.Name = "label13";
			this.label13.Size = new Size(992, 23);
			this.label13.TabIndex = 4;
			this.label13.Text = "With whom do you identify strongly at the moment? Why?";
			this.txtPeople2.Dock = DockStyle.Top;
			this.txtPeople2.Location = new Point(0, 86);
			this.txtPeople2.Multiline = true;
			this.txtPeople2.Name = "txtPeople2";
			this.txtPeople2.Size = new Size(992, 40);
			this.txtPeople2.TabIndex = 3;
			this.label12.Dock = DockStyle.Top;
			this.label12.Location = new Point(0, 63);
			this.label12.Name = "label12";
			this.label12.Size = new Size(992, 23);
			this.label12.TabIndex = 2;
			this.label12.Text = "Who were the people that influenced your life the most? Why?";
			this.txtPeople1.Dock = DockStyle.Top;
			this.txtPeople1.Location = new Point(0, 23);
			this.txtPeople1.Multiline = true;
			this.txtPeople1.Name = "txtPeople1";
			this.txtPeople1.Size = new Size(992, 40);
			this.txtPeople1.TabIndex = 1;
			this.label11.Dock = DockStyle.Top;
			this.label11.Location = new Point(0, 0);
			this.label11.Name = "label11";
			this.label11.Size = new Size(992, 23);
			this.label11.TabIndex = 0;
			this.label11.Text = "Who was your childhood hero? Why?";
			this.tabPage10.Controls.Add(this.txtWords);
			this.tabPage10.Controls.Add(this.label18);
			this.tabPage10.Controls.Add(this.txtWordList);
			this.tabPage10.Controls.Add(this.label17);
			this.tabPage10.Controls.Add(this.label16);
			this.tabPage10.Location = new Point(4, 22);
			this.tabPage10.Name = "tabPage10";
			this.tabPage10.Size = new Size(992, 510);
			this.tabPage10.TabIndex = 5;
			this.tabPage10.Text = "Spoken Words";
			this.tabPage10.UseVisualStyleBackColor = true;
			this.txtWords.Dock = DockStyle.Top;
			this.txtWords.Location = new Point(0, 149);
			this.txtWords.Multiline = true;
			this.txtWords.Name = "txtWords";
			this.txtWords.Size = new Size(992, 80);
			this.txtWords.TabIndex = 14;
			this.label18.Dock = DockStyle.Top;
			this.label18.Location = new Point(0, 126);
			this.label18.Name = "label18";
			this.label18.Size = new Size(992, 23);
			this.label18.TabIndex = 13;
			this.label18.Text = "Now summarize the central themes from your answers and type them below:";
			this.txtWordList.Dock = DockStyle.Top;
			this.txtWordList.Location = new Point(0, 46);
			this.txtWordList.Multiline = true;
			this.txtWordList.Name = "txtWordList";
			this.txtWordList.Size = new Size(992, 80);
			this.txtWordList.TabIndex = 2;
			this.label17.Dock = DockStyle.Top;
			this.label17.Location = new Point(0, 23);
			this.label17.Name = "label17";
			this.label17.Size = new Size(992, 23);
			this.label17.TabIndex = 1;
			this.label17.Text = "Fill these commonly spoken lines in below";
			this.label16.Dock = DockStyle.Top;
			this.label16.Location = new Point(0, 0);
			this.label16.Name = "label16";
			this.label16.Size = new Size(992, 23);
			this.label16.TabIndex = 0;
			this.label16.Text = "Things people say about you has a big impact on your life and often reveal a lot more than you think...";
			this.tpMAnalysis.Controls.Add(this.grpWords);
			this.tpMAnalysis.Controls.Add(this.grpPeople);
			this.tpMAnalysis.Controls.Add(this.grpPassions);
			this.tpMAnalysis.Controls.Add(this.grpDreams);
			this.tpMAnalysis.Controls.Add(this.groupBox6);
			this.tpMAnalysis.Controls.Add(this.grpKeys);
			this.tpMAnalysis.Controls.Add(this.grpSkills);
			this.tpMAnalysis.Controls.Add(this.grpRoles);
			this.tpMAnalysis.Controls.Add(this.groupBox3);
			this.tpMAnalysis.Controls.Add(this.panel1);
			this.tpMAnalysis.Location = new Point(4, 22);
			this.tpMAnalysis.Name = "tpMAnalysis";
			this.tpMAnalysis.Size = new Size(992, 510);
			this.tpMAnalysis.TabIndex = 6;
			this.tpMAnalysis.Text = "Analysis";
			this.tpMAnalysis.UseVisualStyleBackColor = true;
			this.grpWords.Location = new Point(11, 414);
			this.grpWords.Name = "grpWords";
			this.grpWords.Size = new Size(201, 87);
			this.grpWords.TabIndex = 26;
			this.grpWords.TabStop = false;
			this.grpWords.Text = "Words";
			this.grpPeople.Location = new Point(217, 308);
			this.grpPeople.Name = "grpPeople";
			this.grpPeople.Size = new Size(201, 100);
			this.grpPeople.TabIndex = 26;
			this.grpPeople.TabStop = false;
			this.grpPeople.Text = "People";
			this.grpPassions.Location = new Point(11, 308);
			this.grpPassions.Name = "grpPassions";
			this.grpPassions.Size = new Size(201, 100);
			this.grpPassions.TabIndex = 27;
			this.grpPassions.TabStop = false;
			this.grpPassions.Text = "Passions";
			this.grpDreams.Location = new Point(217, 414);
			this.grpDreams.Name = "grpDreams";
			this.grpDreams.Size = new Size(201, 87);
			this.grpDreams.TabIndex = 25;
			this.grpDreams.TabStop = false;
			this.grpDreams.Text = "Dreams";
			this.groupBox6.Controls.Add(this.groupBox11);
			this.groupBox6.Controls.Add(this.groupBox10);
			this.groupBox6.Controls.Add(this.groupBox9);
			this.groupBox6.Controls.Add(this.groupBox8);
			this.groupBox6.Location = new Point(741, 39);
			this.groupBox6.Name = "groupBox6";
			this.groupBox6.Size = new Size(249, 341);
			this.groupBox6.TabIndex = 23;
			this.groupBox6.TabStop = false;
			this.groupBox6.Text = "Who I Am";
			this.groupBox11.Controls.Add(this.txtMTheme4);
			this.groupBox11.Dock = DockStyle.Top;
			this.groupBox11.Location = new Point(3, 253);
			this.groupBox11.Name = "groupBox11";
			this.groupBox11.Size = new Size(243, 80);
			this.groupBox11.TabIndex = 3;
			this.groupBox11.TabStop = false;
			this.groupBox11.Text = "Theme 4";
			this.txtMTheme4.Dock = DockStyle.Top;
			this.txtMTheme4.Location = new Point(3, 16);
			this.txtMTheme4.Multiline = true;
			this.txtMTheme4.Name = "txtMTheme4";
			this.txtMTheme4.Size = new Size(237, 57);
			this.txtMTheme4.TabIndex = 0;
			this.txtMTheme4.DoubleClick += new EventHandler(this.TxtColourClick);
			this.groupBox10.Controls.Add(this.txtMTheme3);
			this.groupBox10.Dock = DockStyle.Top;
			this.groupBox10.Location = new Point(3, 173);
			this.groupBox10.Name = "groupBox10";
			this.groupBox10.Size = new Size(243, 80);
			this.groupBox10.TabIndex = 2;
			this.groupBox10.TabStop = false;
			this.groupBox10.Text = "Theme 3";
			this.txtMTheme3.Dock = DockStyle.Top;
			this.txtMTheme3.Location = new Point(3, 16);
			this.txtMTheme3.Multiline = true;
			this.txtMTheme3.Name = "txtMTheme3";
			this.txtMTheme3.Size = new Size(237, 57);
			this.txtMTheme3.TabIndex = 0;
			this.txtMTheme3.DoubleClick += new EventHandler(this.TxtColourClick);
			this.groupBox9.Controls.Add(this.txtMTheme2);
			this.groupBox9.Dock = DockStyle.Top;
			this.groupBox9.Location = new Point(3, 96);
			this.groupBox9.Name = "groupBox9";
			this.groupBox9.Size = new Size(243, 77);
			this.groupBox9.TabIndex = 1;
			this.groupBox9.TabStop = false;
			this.groupBox9.Text = "Theme 2";
			this.txtMTheme2.Dock = DockStyle.Top;
			this.txtMTheme2.Location = new Point(3, 16);
			this.txtMTheme2.Multiline = true;
			this.txtMTheme2.Name = "txtMTheme2";
			this.txtMTheme2.Size = new Size(237, 57);
			this.txtMTheme2.TabIndex = 0;
			this.txtMTheme2.DoubleClick += new EventHandler(this.TxtColourClick);
			this.groupBox8.Controls.Add(this.txtMTheme1);
			this.groupBox8.Dock = DockStyle.Top;
			this.groupBox8.Location = new Point(3, 16);
			this.groupBox8.Name = "groupBox8";
			this.groupBox8.Size = new Size(243, 80);
			this.groupBox8.TabIndex = 0;
			this.groupBox8.TabStop = false;
			this.groupBox8.Text = "Theme 1";
			this.txtMTheme1.Dock = DockStyle.Top;
			this.txtMTheme1.Location = new Point(3, 16);
			this.txtMTheme1.Multiline = true;
			this.txtMTheme1.Name = "txtMTheme1";
			this.txtMTheme1.Size = new Size(237, 57);
			this.txtMTheme1.TabIndex = 0;
			this.txtMTheme1.DoubleClick += new EventHandler(this.TxtColourClick);
			this.grpKeys.Location = new Point(423, 202);
			this.grpKeys.Name = "grpKeys";
			this.grpKeys.Size = new Size(149, 83);
			this.grpKeys.TabIndex = 22;
			this.grpKeys.TabStop = false;
			this.grpKeys.Text = "Life Keys";
			this.grpSkills.Location = new Point(579, 37);
			this.grpSkills.Name = "grpSkills";
			this.grpSkills.Size = new Size(149, 159);
			this.grpSkills.TabIndex = 20;
			this.grpSkills.TabStop = false;
			this.grpSkills.Text = "7 Life Skills";
			this.grpRoles.Location = new Point(423, 37);
			this.grpRoles.Name = "grpRoles";
			this.grpRoles.Size = new Size(149, 159);
			this.grpRoles.TabIndex = 19;
			this.grpRoles.TabStop = false;
			this.grpRoles.Text = "7 Roles";
			this.groupBox3.Controls.Add(this.groupBox27);
			this.groupBox3.Controls.Add(this.lblM4b);
			this.groupBox3.Controls.Add(this.lblM4);
			this.groupBox3.Controls.Add(this.lblM1b);
			this.groupBox3.Controls.Add(this.lblM1);
			this.groupBox3.Controls.Add(this.txtMBTI1);
			this.groupBox3.Controls.Add(this.txtMBTI4);
			this.groupBox3.Location = new Point(5, 37);
			this.groupBox3.Name = "groupBox3";
			this.groupBox3.Size = new Size(411, 265);
			this.groupBox3.TabIndex = 18;
			this.groupBox3.TabStop = false;
			this.groupBox3.Text = "MBTI";
			this.groupBox27.Controls.Add(this.lblM23b);
			this.groupBox27.Controls.Add(this.lblM3);
			this.groupBox27.Controls.Add(this.lblM2);
			this.groupBox27.Controls.Add(this.txtMBTI2);
			this.groupBox27.Controls.Add(this.txtMBTI3);
			this.groupBox27.Location = new Point(0, 69);
			this.groupBox27.Name = "groupBox27";
			this.groupBox27.Size = new Size(411, 126);
			this.groupBox27.TabIndex = 20;
			this.groupBox27.TabStop = false;
			this.lblM23b.Location = new Point(207, 15);
			this.lblM23b.Name = "lblM23b";
			this.lblM23b.Size = new Size(181, 100);
			this.lblM23b.TabIndex = 23;
			this.lblM23b.Text = "label29";
			this.lblM3.Location = new Point(36, 73);
			this.lblM3.Name = "lblM3";
			this.lblM3.Size = new Size(165, 50);
			this.lblM3.TabIndex = 22;
			this.lblM3.Text = "label27";
			this.lblM2.Location = new Point(36, 15);
			this.lblM2.Name = "lblM2";
			this.lblM2.Size = new Size(165, 50);
			this.lblM2.TabIndex = 21;
			this.lblM2.Text = "label26";
			this.txtMBTI2.Location = new Point(6, 15);
			this.txtMBTI2.MaxLength = 1;
			this.txtMBTI2.Name = "txtMBTI2";
			this.txtMBTI2.ReadOnly = true;
			this.txtMBTI2.Size = new Size(25, 20);
			this.txtMBTI2.TabIndex = 19;
			this.txtMBTI2.Text = "B";
			this.txtMBTI3.Location = new Point(6, 73);
			this.txtMBTI3.MaxLength = 1;
			this.txtMBTI3.Name = "txtMBTI3";
			this.txtMBTI3.ReadOnly = true;
			this.txtMBTI3.Size = new Size(25, 20);
			this.txtMBTI3.TabIndex = 20;
			this.txtMBTI3.Text = "C";
			this.lblM4b.Location = new Point(213, 204);
			this.lblM4b.Name = "lblM4b";
			this.lblM4b.Size = new Size(181, 50);
			this.lblM4b.TabIndex = 19;
			this.lblM4b.Text = "label30";
			this.lblM4.Location = new Point(42, 201);
			this.lblM4.Name = "lblM4";
			this.lblM4.Size = new Size(165, 50);
			this.lblM4.TabIndex = 17;
			this.lblM4.Text = "label28";
			this.lblM1b.Location = new Point(213, 19);
			this.lblM1b.Name = "lblM1b";
			this.lblM1b.Size = new Size(181, 50);
			this.lblM1b.TabIndex = 14;
			this.lblM1b.Text = "label25";
			this.lblM1.Location = new Point(42, 16);
			this.lblM1.Name = "lblM1";
			this.lblM1.Size = new Size(165, 50);
			this.lblM1.TabIndex = 13;
			this.lblM1.Text = "label20";
			this.txtMBTI1.Location = new Point(6, 16);
			this.txtMBTI1.MaxLength = 1;
			this.txtMBTI1.Name = "txtMBTI1";
			this.txtMBTI1.ReadOnly = true;
			this.txtMBTI1.Size = new Size(25, 20);
			this.txtMBTI1.TabIndex = 0;
			this.txtMBTI1.Text = "A";
			this.txtMBTI4.Location = new Point(6, 201);
			this.txtMBTI4.MaxLength = 1;
			this.txtMBTI4.Name = "txtMBTI4";
			this.txtMBTI4.ReadOnly = true;
			this.txtMBTI4.Size = new Size(25, 20);
			this.txtMBTI4.TabIndex = 3;
			this.txtMBTI4.Text = "D";
			this.panel1.Controls.Add(this.dtpMDate);
			this.panel1.Controls.Add(this.txtMSurname);
			this.panel1.Controls.Add(this.txtMName);
			this.panel1.Controls.Add(this.btnClear);
			this.panel1.Controls.Add(this.txtColour);
			this.panel1.Controls.Add(this.button6);
			this.panel1.Controls.Add(this.btnMColour4);
			this.panel1.Controls.Add(this.btnMColour3);
			this.panel1.Controls.Add(this.btnMColour2);
			this.panel1.Controls.Add(this.btnMColour1);
			this.panel1.Dock = DockStyle.Top;
			this.panel1.Location = new Point(0, 0);
			this.panel1.Name = "panel1";
			this.panel1.Size = new Size(992, 31);
			this.panel1.TabIndex = 17;
			this.dtpMDate.Enabled = false;
			this.dtpMDate.Location = new Point(683, 6);
			this.dtpMDate.Name = "dtpMDate";
			this.dtpMDate.Size = new Size(200, 20);
			this.dtpMDate.TabIndex = 9;
			this.txtMSurname.Location = new Point(553, 6);
			this.txtMSurname.Name = "txtMSurname";
			this.txtMSurname.Size = new Size(124, 20);
			this.txtMSurname.TabIndex = 8;
			this.txtMName.Location = new Point(423, 5);
			this.txtMName.Name = "txtMName";
			this.txtMName.Size = new Size(124, 20);
			this.txtMName.TabIndex = 7;
			this.btnClear.BackColor = SystemColors.Window;
			this.btnClear.Location = new Point(173, 3);
			this.btnClear.Name = "btnClear";
			this.btnClear.Size = new Size(36, 23);
			this.btnClear.TabIndex = 6;
			this.btnClear.UseVisualStyleBackColor = false;
			this.btnClear.Click += new EventHandler(this.ColourClick);
			this.txtColour.BackColor = SystemColors.Window;
			this.txtColour.Location = new Point(242, 5);
			this.txtColour.Name = "txtColour";
			this.txtColour.ReadOnly = true;
			this.txtColour.Size = new Size(53, 20);
			this.txtColour.TabIndex = 5;
			this.txtColour.Click += new EventHandler(this.TxtColourClick);
			this.txtColour.BackColorChanged += new EventHandler(this.TxtColourBackColorChanged);
			this.txtColour.KeyDown += new KeyEventHandler(this.TxtColourKeyDown);
			this.button6.Location = new Point(319, 3);
			this.button6.Name = "button6";
			this.button6.Size = new Size(75, 23);
			this.button6.TabIndex = 4;
			this.button6.Text = "Colours ...";
			this.button6.UseVisualStyleBackColor = true;
			this.button6.Visible = false;
			this.btnMColour4.BackColor = Color.Yellow;
			this.btnMColour4.Location = new Point(131, 3);
			this.btnMColour4.Name = "btnMColour4";
			this.btnMColour4.Size = new Size(36, 23);
			this.btnMColour4.TabIndex = 3;
			this.btnMColour4.UseVisualStyleBackColor = false;
			this.btnMColour4.Click += new EventHandler(this.ColourClick);
			this.btnMColour3.BackColor = Color.LightSteelBlue;
			this.btnMColour3.Location = new Point(89, 3);
			this.btnMColour3.Name = "btnMColour3";
			this.btnMColour3.Size = new Size(36, 23);
			this.btnMColour3.TabIndex = 2;
			this.btnMColour3.UseVisualStyleBackColor = false;
			this.btnMColour3.Click += new EventHandler(this.ColourClick);
			this.btnMColour2.BackColor = Color.GreenYellow;
			this.btnMColour2.Location = new Point(47, 3);
			this.btnMColour2.Name = "btnMColour2";
			this.btnMColour2.Size = new Size(36, 23);
			this.btnMColour2.TabIndex = 1;
			this.btnMColour2.UseVisualStyleBackColor = false;
			this.btnMColour2.Click += new EventHandler(this.ColourClick);
			this.btnMColour1.BackColor = Color.FromArgb(255, 192, 192);
			this.btnMColour1.Location = new Point(5, 3);
			this.btnMColour1.Name = "btnMColour1";
			this.btnMColour1.Size = new Size(36, 23);
			this.btnMColour1.TabIndex = 0;
			this.btnMColour1.UseVisualStyleBackColor = false;
			this.btnMColour1.Click += new EventHandler(this.ColourClick);
			this.tabPage4.Controls.Add(this.tabCareer);
			this.tabPage4.Location = new Point(4, 22);
			this.tabPage4.Name = "tabPage4";
			this.tabPage4.Size = new Size(1000, 536);
			this.tabPage4.TabIndex = 3;
			this.tabPage4.Text = "Career";
			this.tabPage4.UseVisualStyleBackColor = true;
			this.tabCareer.Controls.Add(this.tabPage11);
			this.tabCareer.Controls.Add(this.tabPage12);
			this.tabCareer.Controls.Add(this.tabPage13);
			this.tabCareer.Controls.Add(this.tpCAnalysis);
			this.tabCareer.Dock = DockStyle.Fill;
			this.tabCareer.Location = new Point(0, 0);
			this.tabCareer.Name = "tabCareer";
			this.tabCareer.SelectedIndex = 0;
			this.tabCareer.Size = new Size(1000, 536);
			this.tabCareer.TabIndex = 1;
			this.tabCareer.SelectedIndexChanged += new EventHandler(this.TabControl2SelectedIndexChanged);
			this.tabPage11.Controls.Add(this.clbPeople);
			this.tabPage11.Location = new Point(4, 22);
			this.tabPage11.Name = "tabPage11";
			this.tabPage11.Padding = new Padding(3);
			this.tabPage11.Size = new Size(992, 510);
			this.tabPage11.TabIndex = 0;
			this.tabPage11.Text = "People Orientation";
			this.tabPage11.UseVisualStyleBackColor = true;
			this.clbPeople.Dock = DockStyle.Fill;
			this.clbPeople.FormattingEnabled = true;
			this.clbPeople.Location = new Point(3, 3);
			this.clbPeople.Name = "clbPeople";
			this.clbPeople.Size = new Size(986, 504);
			this.clbPeople.TabIndex = 0;
			this.clbPeople.SelectedIndexChanged += new EventHandler(this.CheckedListBox1SelectedIndexChanged);
			this.tabPage12.Controls.Add(this.clbPriorities);
			this.tabPage12.Location = new Point(4, 22);
			this.tabPage12.Name = "tabPage12";
			this.tabPage12.Padding = new Padding(3);
			this.tabPage12.Size = new Size(992, 510);
			this.tabPage12.TabIndex = 1;
			this.tabPage12.Text = "Priorities";
			this.tabPage12.UseVisualStyleBackColor = true;
			this.clbPriorities.Dock = DockStyle.Fill;
			this.clbPriorities.FormattingEnabled = true;
			this.clbPriorities.Location = new Point(3, 3);
			this.clbPriorities.Name = "clbPriorities";
			this.clbPriorities.Size = new Size(986, 504);
			this.clbPriorities.TabIndex = 3;
			this.clbPriorities.ItemCheck += new ItemCheckEventHandler(this.ClbPrioritiesItemCheck);
			this.clbPriorities.SelectedIndexChanged += new EventHandler(this.CheckedListBox1SelectedIndexChanged);
			this.tabPage13.Controls.Add(this.txtWork);
			this.tabPage13.Controls.Add(this.label19);
			this.tabPage13.Controls.Add(this.txtWork4);
			this.tabPage13.Controls.Add(this.label21);
			this.tabPage13.Controls.Add(this.txtWork3);
			this.tabPage13.Controls.Add(this.label22);
			this.tabPage13.Controls.Add(this.txtWork2);
			this.tabPage13.Controls.Add(this.label23);
			this.tabPage13.Controls.Add(this.txtWork1);
			this.tabPage13.Controls.Add(this.label24);
			this.tabPage13.Location = new Point(4, 22);
			this.tabPage13.Name = "tabPage13";
			this.tabPage13.Size = new Size(992, 510);
			this.tabPage13.TabIndex = 2;
			this.tabPage13.Text = "Work Environment";
			this.tabPage13.UseVisualStyleBackColor = true;
			this.txtWork.Dock = DockStyle.Top;
			this.txtWork.Location = new Point(0, 195);
			this.txtWork.Multiline = true;
			this.txtWork.Name = "txtWork";
			this.txtWork.Size = new Size(992, 80);
			this.txtWork.TabIndex = 11;
			this.label19.Dock = DockStyle.Top;
			this.label19.Location = new Point(0, 172);
			this.label19.Name = "label19";
			this.label19.Size = new Size(992, 23);
			this.label19.TabIndex = 10;
			this.label19.Text = "Now summarize the central themes from your answers and type them below:";
			this.txtWork4.Dock = DockStyle.Top;
			this.txtWork4.Location = new Point(0, 152);
			this.txtWork4.Name = "txtWork4";
			this.txtWork4.Size = new Size(992, 20);
			this.txtWork4.TabIndex = 8;
			this.label21.Dock = DockStyle.Top;
			this.label21.Location = new Point(0, 129);
			this.label21.Name = "label21";
			this.label21.Size = new Size(992, 23);
			this.label21.TabIndex = 3;
			this.label21.Text = "An undefined changing environment makes me feel";
			this.txtWork3.Dock = DockStyle.Top;
			this.txtWork3.Location = new Point(0, 109);
			this.txtWork3.Name = "txtWork3";
			this.txtWork3.Size = new Size(992, 20);
			this.txtWork3.TabIndex = 7;
			this.label22.Dock = DockStyle.Top;
			this.label22.Location = new Point(0, 86);
			this.label22.Name = "label22";
			this.label22.Size = new Size(992, 23);
			this.label22.TabIndex = 2;
			this.label22.Text = "Fixed structure makes me feel";
			this.txtWork2.Dock = DockStyle.Top;
			this.txtWork2.Location = new Point(0, 66);
			this.txtWork2.Name = "txtWork2";
			this.txtWork2.Size = new Size(992, 20);
			this.txtWork2.TabIndex = 6;
			this.label23.Dock = DockStyle.Top;
			this.label23.Location = new Point(0, 43);
			this.label23.Name = "label23";
			this.label23.Size = new Size(992, 23);
			this.label23.TabIndex = 1;
			this.label23.Text = "I am creative in the following ways";
			this.txtWork1.Dock = DockStyle.Top;
			this.txtWork1.Location = new Point(0, 23);
			this.txtWork1.Name = "txtWork1";
			this.txtWork1.Size = new Size(992, 20);
			this.txtWork1.TabIndex = 5;
			this.label24.Dock = DockStyle.Top;
			this.label24.Location = new Point(0, 0);
			this.label24.Name = "label24";
			this.label24.Size = new Size(992, 23);
			this.label24.TabIndex = 0;
			this.label24.Text = "My ideal work environment";
			this.tpCAnalysis.Controls.Add(this.panel2);
			this.tpCAnalysis.Controls.Add(this.groupBox5);
			this.tpCAnalysis.Controls.Add(this.groupBox29);
			this.tpCAnalysis.Controls.Add(this.groupBox4);
			this.tpCAnalysis.Controls.Add(this.grpWork);
			this.tpCAnalysis.Controls.Add(this.grpKeysC);
			this.tpCAnalysis.Controls.Add(this.grpSkillsC);
			this.tpCAnalysis.Controls.Add(this.grpRolesC);
			this.tpCAnalysis.Controls.Add(this.grpPriorities);
			this.tpCAnalysis.Controls.Add(this.groupBox7);
			this.tpCAnalysis.Controls.Add(this.grpPeopleC);
			this.tpCAnalysis.Location = new Point(4, 22);
			this.tpCAnalysis.Name = "tpCAnalysis";
			this.tpCAnalysis.Size = new Size(992, 510);
			this.tpCAnalysis.TabIndex = 3;
			this.tpCAnalysis.Text = "Analysis";
			this.tpCAnalysis.UseVisualStyleBackColor = true;
			this.panel2.Controls.Add(this.dtpCDate);
			this.panel2.Controls.Add(this.txtCSurname);
			this.panel2.Controls.Add(this.txtCName);
			this.panel2.Controls.Add(this.button12);
			this.panel2.Controls.Add(this.txtColourC);
			this.panel2.Controls.Add(this.button7);
			this.panel2.Controls.Add(this.btnCColour4);
			this.panel2.Controls.Add(this.btnCColour3);
			this.panel2.Controls.Add(this.btnCColour2);
			this.panel2.Controls.Add(this.btnCColour1);
			this.panel2.Dock = DockStyle.Top;
			this.panel2.Location = new Point(0, 0);
			this.panel2.Name = "panel2";
			this.panel2.Size = new Size(992, 31);
			this.panel2.TabIndex = 31;
			this.dtpCDate.Enabled = false;
			this.dtpCDate.Location = new Point(683, 6);
			this.dtpCDate.Name = "dtpCDate";
			this.dtpCDate.Size = new Size(200, 20);
			this.dtpCDate.TabIndex = 12;
			this.txtCSurname.Location = new Point(553, 6);
			this.txtCSurname.Name = "txtCSurname";
			this.txtCSurname.Size = new Size(124, 20);
			this.txtCSurname.TabIndex = 11;
			this.txtCName.Location = new Point(423, 5);
			this.txtCName.Name = "txtCName";
			this.txtCName.Size = new Size(124, 20);
			this.txtCName.TabIndex = 10;
			this.button12.BackColor = SystemColors.Window;
			this.button12.Location = new Point(174, 3);
			this.button12.Name = "button12";
			this.button12.Size = new Size(36, 23);
			this.button12.TabIndex = 6;
			this.button12.UseVisualStyleBackColor = false;
			this.button12.Click += new EventHandler(this.ColourClick);
			this.txtColourC.Location = new Point(242, 5);
			this.txtColourC.Name = "txtColourC";
			this.txtColourC.ReadOnly = true;
			this.txtColourC.Size = new Size(53, 20);
			this.txtColourC.TabIndex = 5;
			this.button7.Location = new Point(319, 3);
			this.button7.Name = "button7";
			this.button7.Size = new Size(75, 23);
			this.button7.TabIndex = 4;
			this.button7.Text = "Colours ...";
			this.button7.UseVisualStyleBackColor = true;
			this.button7.Visible = false;
			this.btnCColour4.BackColor = Color.Yellow;
			this.btnCColour4.Location = new Point(131, 3);
			this.btnCColour4.Name = "btnCColour4";
			this.btnCColour4.Size = new Size(36, 23);
			this.btnCColour4.TabIndex = 3;
			this.btnCColour4.UseVisualStyleBackColor = false;
			this.btnCColour4.Click += new EventHandler(this.ColourClick);
			this.btnCColour3.BackColor = Color.Blue;
			this.btnCColour3.Location = new Point(89, 3);
			this.btnCColour3.Name = "btnCColour3";
			this.btnCColour3.Size = new Size(36, 23);
			this.btnCColour3.TabIndex = 2;
			this.btnCColour3.UseVisualStyleBackColor = false;
			this.btnCColour3.Click += new EventHandler(this.ColourClick);
			this.btnCColour2.BackColor = Color.Green;
			this.btnCColour2.Location = new Point(47, 3);
			this.btnCColour2.Name = "btnCColour2";
			this.btnCColour2.Size = new Size(36, 23);
			this.btnCColour2.TabIndex = 1;
			this.btnCColour2.UseVisualStyleBackColor = false;
			this.btnCColour2.Click += new EventHandler(this.ColourClick);
			this.btnCColour1.BackColor = Color.Red;
			this.btnCColour1.Location = new Point(5, 3);
			this.btnCColour1.Name = "btnCColour1";
			this.btnCColour1.Size = new Size(36, 23);
			this.btnCColour1.TabIndex = 0;
			this.btnCColour1.UseVisualStyleBackColor = false;
			this.btnCColour1.Click += new EventHandler(this.ColourClick);
			this.groupBox5.Controls.Add(this.listBox1);
			this.groupBox5.Location = new Point(425, 202);
			this.groupBox5.Name = "groupBox5";
			this.groupBox5.Size = new Size(303, 176);
			this.groupBox5.TabIndex = 30;
			this.groupBox5.TabStop = false;
			this.groupBox5.Text = "Possible Careers";
			this.listBox1.Dock = DockStyle.Fill;
			this.listBox1.FormattingEnabled = true;
			this.listBox1.Location = new Point(3, 16);
			this.listBox1.Name = "listBox1";
			this.listBox1.Size = new Size(297, 157);
			this.listBox1.TabIndex = 22;
			this.groupBox29.Controls.Add(this.txtRecommendation);
			this.groupBox29.Location = new Point(423, 388);
			this.groupBox29.Name = "groupBox29";
			this.groupBox29.Size = new Size(306, 100);
			this.groupBox29.TabIndex = 29;
			this.groupBox29.TabStop = false;
			this.groupBox29.Text = "Recommendation";
			this.txtRecommendation.Dock = DockStyle.Fill;
			this.txtRecommendation.Location = new Point(3, 16);
			this.txtRecommendation.Multiline = true;
			this.txtRecommendation.Name = "txtRecommendation";
			this.txtRecommendation.Size = new Size(300, 81);
			this.txtRecommendation.TabIndex = 0;
			this.groupBox4.Controls.Add(this.groupBox28);
			this.groupBox4.Controls.Add(this.lblC4b);
			this.groupBox4.Controls.Add(this.lblC4);
			this.groupBox4.Controls.Add(this.lblC1b);
			this.groupBox4.Controls.Add(this.lblC1);
			this.groupBox4.Controls.Add(this.txtMBTI1c);
			this.groupBox4.Controls.Add(this.txtMBTI4c);
			this.groupBox4.Location = new Point(3, 38);
			this.groupBox4.Name = "groupBox4";
			this.groupBox4.Size = new Size(411, 265);
			this.groupBox4.TabIndex = 28;
			this.groupBox4.TabStop = false;
			this.groupBox4.Text = "MBTI";
			this.groupBox28.Controls.Add(this.lblC23);
			this.groupBox28.Controls.Add(this.lblC3);
			this.groupBox28.Controls.Add(this.lblC2);
			this.groupBox28.Controls.Add(this.txtMBTI2c);
			this.groupBox28.Controls.Add(this.txtMBTI3c);
			this.groupBox28.Location = new Point(-1, 69);
			this.groupBox28.Name = "groupBox28";
			this.groupBox28.Size = new Size(413, 126);
			this.groupBox28.TabIndex = 20;
			this.groupBox28.TabStop = false;
			this.lblC23.Location = new Point(207, 15);
			this.lblC23.Name = "lblC23";
			this.lblC23.Size = new Size(181, 100);
			this.lblC23.TabIndex = 23;
			this.lblC23.Text = "label29";
			this.lblC3.Location = new Point(36, 73);
			this.lblC3.Name = "lblC3";
			this.lblC3.Size = new Size(165, 50);
			this.lblC3.TabIndex = 22;
			this.lblC3.Text = "label27";
			this.lblC2.Location = new Point(36, 15);
			this.lblC2.Name = "lblC2";
			this.lblC2.Size = new Size(165, 50);
			this.lblC2.TabIndex = 21;
			this.lblC2.Text = "label26";
			this.txtMBTI2c.Location = new Point(7, 15);
			this.txtMBTI2c.MaxLength = 1;
			this.txtMBTI2c.Name = "txtMBTI2c";
			this.txtMBTI2c.ReadOnly = true;
			this.txtMBTI2c.Size = new Size(25, 20);
			this.txtMBTI2c.TabIndex = 19;
			this.txtMBTI2c.Text = "B";
			this.txtMBTI3c.Location = new Point(7, 79);
			this.txtMBTI3c.MaxLength = 1;
			this.txtMBTI3c.Name = "txtMBTI3c";
			this.txtMBTI3c.ReadOnly = true;
			this.txtMBTI3c.Size = new Size(25, 20);
			this.txtMBTI3c.TabIndex = 20;
			this.txtMBTI3c.Text = "C";
			this.lblC4b.Location = new Point(213, 204);
			this.lblC4b.Name = "lblC4b";
			this.lblC4b.Size = new Size(181, 50);
			this.lblC4b.TabIndex = 19;
			this.lblC4b.Text = "label30";
			this.lblC4.Location = new Point(42, 201);
			this.lblC4.Name = "lblC4";
			this.lblC4.Size = new Size(165, 50);
			this.lblC4.TabIndex = 17;
			this.lblC4.Text = "label28";
			this.lblC1b.Location = new Point(213, 19);
			this.lblC1b.Name = "lblC1b";
			this.lblC1b.Size = new Size(181, 50);
			this.lblC1b.TabIndex = 14;
			this.lblC1b.Text = "label25";
			this.lblC1.Location = new Point(42, 16);
			this.lblC1.Name = "lblC1";
			this.lblC1.Size = new Size(165, 50);
			this.lblC1.TabIndex = 13;
			this.lblC1.Text = "label20";
			this.txtMBTI1c.Location = new Point(6, 16);
			this.txtMBTI1c.MaxLength = 1;
			this.txtMBTI1c.Name = "txtMBTI1c";
			this.txtMBTI1c.ReadOnly = true;
			this.txtMBTI1c.Size = new Size(25, 20);
			this.txtMBTI1c.TabIndex = 0;
			this.txtMBTI1c.Text = "A";
			this.txtMBTI4c.Location = new Point(6, 201);
			this.txtMBTI4c.MaxLength = 1;
			this.txtMBTI4c.Name = "txtMBTI4c";
			this.txtMBTI4c.ReadOnly = true;
			this.txtMBTI4c.Size = new Size(25, 20);
			this.txtMBTI4c.TabIndex = 3;
			this.txtMBTI4c.Text = "D";
			this.grpWork.Location = new Point(9, 408);
			this.grpWork.Name = "grpWork";
			this.grpWork.Size = new Size(201, 80);
			this.grpWork.TabIndex = 24;
			this.grpWork.TabStop = false;
			this.grpWork.Text = "Work";
			this.grpKeysC.Location = new Point(216, 408);
			this.grpKeysC.Name = "grpKeysC";
			this.grpKeysC.Size = new Size(201, 80);
			this.grpKeysC.TabIndex = 27;
			this.grpKeysC.TabStop = false;
			this.grpKeysC.Text = "Life Keys";
			this.grpSkillsC.Location = new Point(579, 37);
			this.grpSkillsC.Name = "grpSkillsC";
			this.grpSkillsC.Size = new Size(150, 159);
			this.grpSkillsC.TabIndex = 26;
			this.grpSkillsC.TabStop = false;
			this.grpSkillsC.Text = "7 Life Skills";
			this.grpRolesC.Location = new Point(423, 37);
			this.grpRolesC.Name = "grpRolesC";
			this.grpRolesC.Size = new Size(150, 159);
			this.grpRolesC.TabIndex = 25;
			this.grpRolesC.TabStop = false;
			this.grpRolesC.Text = "7 Roles";
			this.grpPriorities.Controls.Add(this.groupBox17);
			this.grpPriorities.Location = new Point(9, 309);
			this.grpPriorities.Name = "grpPriorities";
			this.grpPriorities.Size = new Size(201, 93);
			this.grpPriorities.TabIndex = 24;
			this.grpPriorities.TabStop = false;
			this.grpPriorities.Text = "Priorities";
			this.groupBox17.Location = new Point(0, 99);
			this.groupBox17.Name = "groupBox17";
			this.groupBox17.Size = new Size(201, 100);
			this.groupBox17.TabIndex = 25;
			this.groupBox17.TabStop = false;
			this.groupBox17.Text = "Work";
			this.groupBox7.Controls.Add(this.groupBox12);
			this.groupBox7.Controls.Add(this.groupBox13);
			this.groupBox7.Controls.Add(this.groupBox14);
			this.groupBox7.Controls.Add(this.groupBox15);
			this.groupBox7.Location = new Point(744, 37);
			this.groupBox7.Name = "groupBox7";
			this.groupBox7.Size = new Size(249, 341);
			this.groupBox7.TabIndex = 24;
			this.groupBox7.TabStop = false;
			this.groupBox7.Text = "Who I Am";
			this.groupBox12.Controls.Add(this.txtCTheme4);
			this.groupBox12.Dock = DockStyle.Top;
			this.groupBox12.Location = new Point(3, 256);
			this.groupBox12.Name = "groupBox12";
			this.groupBox12.Size = new Size(243, 80);
			this.groupBox12.TabIndex = 3;
			this.groupBox12.TabStop = false;
			this.groupBox12.Text = "Theme 4";
			this.txtCTheme4.Dock = DockStyle.Top;
			this.txtCTheme4.Location = new Point(3, 16);
			this.txtCTheme4.Multiline = true;
			this.txtCTheme4.Name = "txtCTheme4";
			this.txtCTheme4.Size = new Size(237, 57);
			this.txtCTheme4.TabIndex = 0;
			this.txtCTheme4.DoubleClick += new EventHandler(this.TxtColourClick);
			this.txtCTheme4.KeyDown += new KeyEventHandler(this.TxtColourKeyDown);
			this.groupBox13.Controls.Add(this.txtCTheme3);
			this.groupBox13.Dock = DockStyle.Top;
			this.groupBox13.Location = new Point(3, 176);
			this.groupBox13.Name = "groupBox13";
			this.groupBox13.Size = new Size(243, 80);
			this.groupBox13.TabIndex = 2;
			this.groupBox13.TabStop = false;
			this.groupBox13.Text = "Theme 3";
			this.txtCTheme3.Dock = DockStyle.Top;
			this.txtCTheme3.Location = new Point(3, 16);
			this.txtCTheme3.Multiline = true;
			this.txtCTheme3.Name = "txtCTheme3";
			this.txtCTheme3.Size = new Size(237, 57);
			this.txtCTheme3.TabIndex = 0;
			this.txtCTheme3.DoubleClick += new EventHandler(this.TxtColourClick);
			this.txtCTheme3.KeyDown += new KeyEventHandler(this.TxtColourKeyDown);
			this.groupBox14.Controls.Add(this.txtCTheme2);
			this.groupBox14.Dock = DockStyle.Top;
			this.groupBox14.Location = new Point(3, 96);
			this.groupBox14.Name = "groupBox14";
			this.groupBox14.Size = new Size(243, 80);
			this.groupBox14.TabIndex = 1;
			this.groupBox14.TabStop = false;
			this.groupBox14.Text = "Theme 2";
			this.txtCTheme2.Dock = DockStyle.Top;
			this.txtCTheme2.Location = new Point(3, 16);
			this.txtCTheme2.Multiline = true;
			this.txtCTheme2.Name = "txtCTheme2";
			this.txtCTheme2.Size = new Size(237, 57);
			this.txtCTheme2.TabIndex = 0;
			this.txtCTheme2.DoubleClick += new EventHandler(this.TxtColourClick);
			this.txtCTheme2.KeyDown += new KeyEventHandler(this.TxtColourKeyDown);
			this.groupBox15.Controls.Add(this.txtCTheme1);
			this.groupBox15.Dock = DockStyle.Top;
			this.groupBox15.Location = new Point(3, 16);
			this.groupBox15.Name = "groupBox15";
			this.groupBox15.Size = new Size(243, 80);
			this.groupBox15.TabIndex = 0;
			this.groupBox15.TabStop = false;
			this.groupBox15.Text = "Theme 1";
			this.txtCTheme1.Dock = DockStyle.Top;
			this.txtCTheme1.Location = new Point(3, 16);
			this.txtCTheme1.Multiline = true;
			this.txtCTheme1.Name = "txtCTheme1";
			this.txtCTheme1.Size = new Size(237, 57);
			this.txtCTheme1.TabIndex = 0;
			this.txtCTheme1.DoubleClick += new EventHandler(this.TxtColourClick);
			this.txtCTheme1.KeyDown += new KeyEventHandler(this.TxtColourKeyDown);
			this.grpPeopleC.Location = new Point(216, 309);
			this.grpPeopleC.Name = "grpPeopleC";
			this.grpPeopleC.Size = new Size(201, 93);
			this.grpPeopleC.TabIndex = 23;
			this.grpPeopleC.TabStop = false;
			this.grpPeopleC.Text = "People";
			this.groupBox24.Location = new Point(0, 99);
			this.groupBox24.Name = "groupBox24";
			this.groupBox24.Size = new Size(201, 100);
			this.groupBox24.TabIndex = 25;
			this.groupBox24.TabStop = false;
			this.groupBox24.Text = "Work";
			this.logo.Anchor = (AnchorStyles.Bottom | AnchorStyles.Right);
			this.logo.Image = (Image)componentResourceManager.GetObject("logo.Image");
			this.logo.Location = new Point(755, 428);
			this.logo.Name = "logo";
			this.logo.Size = new Size(236, 118);
			this.logo.SizeMode = PictureBoxSizeMode.StretchImage;
			this.logo.TabIndex = 25;
			this.logo.TabStop = false;
			this.tmrAutoSave.Interval = 10000;
			this.tmrAutoSave.Tick += new EventHandler(this.TmrAutoSaveTick);
			this.lblCopyright.BackColor = SystemColors.Window;
			this.lblCopyright.Location = new Point(756, 530);
			this.lblCopyright.Name = "lblCopyright";
			this.lblCopyright.Size = new Size(150, 15);
			this.lblCopyright.TabIndex = 26;
			this.lblCopyright.Text = "Copyright © Abel Loedolff";
			base.AutoScaleDimensions = new SizeF(6f, 13f);
			base.AutoScaleMode = AutoScaleMode.Font;
			base.ClientSize = new Size(1008, 562);
			base.Controls.Add(this.lblCopyright);
			base.Controls.Add(this.logo);
			base.Controls.Add(this.tabControl1);
			this.Font = new Font("Microsoft Sans Serif", 8.25f, FontStyle.Regular, GraphicsUnit.Point, 0);
			base.Name = "Form1";
			this.Text = "Mission & Career Assessment";
			base.FormClosing += new FormClosingEventHandler(this.Form1FormClosing);
			base.Load += new EventHandler(this.Form1_Load);
			base.Shown += new EventHandler(this.Form1_Shown);
			this.tabControl1.ResumeLayout(false);
			this.tabPage1.ResumeLayout(false);
			this.groupBox16.ResumeLayout(false);
			this.groupBox16.PerformLayout();
			this.groupBox2.ResumeLayout(false);
			this.groupBox2.PerformLayout();
			this.groupBox1.ResumeLayout(false);
			this.groupBox1.PerformLayout();
			this.tabPage3.ResumeLayout(false);
			this.tabMission.ResumeLayout(false);
			this.tabPage5.ResumeLayout(false);
			this.tabPage6.ResumeLayout(false);
			this.tabPage7.ResumeLayout(false);
			this.tabPage7.PerformLayout();
			this.tabPage8.ResumeLayout(false);
			this.tabPage8.PerformLayout();
			this.tabPage9.ResumeLayout(false);
			this.tabPage9.PerformLayout();
			this.tabPage10.ResumeLayout(false);
			this.tabPage10.PerformLayout();
			this.tpMAnalysis.ResumeLayout(false);
			this.groupBox6.ResumeLayout(false);
			this.groupBox11.ResumeLayout(false);
			this.groupBox11.PerformLayout();
			this.groupBox10.ResumeLayout(false);
			this.groupBox10.PerformLayout();
			this.groupBox9.ResumeLayout(false);
			this.groupBox9.PerformLayout();
			this.groupBox8.ResumeLayout(false);
			this.groupBox8.PerformLayout();
			this.groupBox3.ResumeLayout(false);
			this.groupBox3.PerformLayout();
			this.groupBox27.ResumeLayout(false);
			this.groupBox27.PerformLayout();
			this.panel1.ResumeLayout(false);
			this.panel1.PerformLayout();
			this.tabPage4.ResumeLayout(false);
			this.tabCareer.ResumeLayout(false);
			this.tabPage11.ResumeLayout(false);
			this.tabPage12.ResumeLayout(false);
			this.tabPage13.ResumeLayout(false);
			this.tabPage13.PerformLayout();
			this.tpCAnalysis.ResumeLayout(false);
			this.panel2.ResumeLayout(false);
			this.panel2.PerformLayout();
			this.groupBox5.ResumeLayout(false);
			this.groupBox29.ResumeLayout(false);
			this.groupBox29.PerformLayout();
			this.groupBox4.ResumeLayout(false);
			this.groupBox4.PerformLayout();
			this.groupBox28.ResumeLayout(false);
			this.groupBox28.PerformLayout();
			this.grpPriorities.ResumeLayout(false);
			this.groupBox7.ResumeLayout(false);
			this.groupBox12.ResumeLayout(false);
			this.groupBox12.PerformLayout();
			this.groupBox13.ResumeLayout(false);
			this.groupBox13.PerformLayout();
			this.groupBox14.ResumeLayout(false);
			this.groupBox14.PerformLayout();
			this.groupBox15.ResumeLayout(false);
			this.groupBox15.PerformLayout();
			((ISupportInitialize)this.logo).EndInit();
			base.ResumeLayout(false);
		}
	}
}
