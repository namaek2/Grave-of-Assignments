using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Threading;
using WpfApp1.Classes;

namespace WpfApp1
{
    /// <summary>
    /// MainWindow.xaml에 대한 상호 작용 논리
    /// </summary>
    public partial class MainWindow : Window
    {
        double lastNumber;
        double result = 0;
        double newNumber;

        public enum SelectedOperator
        {
            Addition, 
            Substraction, 
            Multiplication, 
            Division,
            SquareRoot,
            Sqaured,
            DivX
        }

        SelectedOperator selectedOperator;

        public MainWindow()
        {
            InitializeComponent();
            negateButton.Click += NegateButton_Click;
            acButton.Click += AcButton_Click;
            percentButton.Click += PercentButton_Click;
            showLabel.Content = "0";
            resultLabel.Content = "0";
        }

        #region        
        long Firsttime = 0;   
        private bool One_Click()
        {
            long CurrentTime = DateTime.Now.Ticks;
            if (CurrentTime - Firsttime < 1000000)
            {
                Firsttime = CurrentTime;   
                return false;  
            }
            else
            {
                Firsttime = CurrentTime;   
                return true;  
            }
        }
        #endregion

        private void NegateButton_Click(object sender, RoutedEventArgs e)
        {
            if (One_Click())
            {
                if (double.TryParse(resultLabel.Content.ToString(), out lastNumber))
                {
                    lastNumber = (-1) * lastNumber;
                    resultLabel.Content = lastNumber.ToString();
                }
            }   
        }

       

        private void resultButton_Click(object sender, RoutedEventArgs e)
        {
            if (showLabel.Content.ToString().Contains("="))
                return;

            if (One_Click())
            {
                if (double.TryParse(resultLabel.Content.ToString(), out newNumber))
                {
                    if (showLabel.Content.ToString() != "0")
                        showLabel.Content += resultLabel.Content.ToString();
                    else
                        showLabel.Content = lastNumber.ToString();

                    switch (selectedOperator)
                    {
                        case SelectedOperator.Addition:
                            result = SimpleMath.Add(lastNumber, newNumber);
                            break;
                        case SelectedOperator.Substraction:
                            result = SimpleMath.Sub(lastNumber, newNumber);
                            break;

                        case SelectedOperator.Multiplication:
                            result = SimpleMath.Mul(lastNumber, newNumber);
                            break;

                        case SelectedOperator.Division:
                            result = SimpleMath.Div(lastNumber, newNumber);
                            break;
                    }
                    showLabel.Content += " = ";
                    resultLabel.Content = result.ToString();
                    calcs.Items.Insert(0, showLabel.Content.ToString() + result.ToString());
                }
            }
        }
        private void pointButton_Click(object sender, RoutedEventArgs e)
        {
            if (double.TryParse(resultLabel.Content.ToString(), out lastNumber))
            {
                if(lastNumber==(int)lastNumber)
                {
                    showLabel.Content += ".";
                    resultLabel.Content += ".";
                }
            }
        }
        int check = 0;
        private void OperatorButton_Click(object sender, RoutedEventArgs e)
        {
            if (One_Click())
            {
                if (showLabel.Content.ToString().Contains("+") || showLabel.Content.ToString().Contains("-") || showLabel.Content.ToString().Contains("*") || showLabel.Content.ToString().Contains("/"))
                {
                    if (double.TryParse(resultLabel.Content.ToString(), out newNumber))
                    {
                        check = 1;
                        switch (selectedOperator)
                        {
                            case SelectedOperator.Addition:
                                calcs.Items.Insert(0, lastNumber.ToString() + " + " + newNumber.ToString() + " = " + SimpleMath.Add(lastNumber, newNumber).ToString());
                                lastNumber = SimpleMath.Add(lastNumber, newNumber);
                                showLabel.Content = lastNumber.ToString();
                                resultLabel.Content = showLabel.Content;
                                break;
                            case SelectedOperator.Substraction:
                                calcs.Items.Insert(0, lastNumber.ToString() + " - " + newNumber.ToString() + " = " + SimpleMath.Sub(lastNumber, newNumber).ToString());
                                lastNumber = SimpleMath.Sub(lastNumber, newNumber);
                                showLabel.Content = lastNumber.ToString();
                                resultLabel.Content = showLabel.Content;
                                break;

                            case SelectedOperator.Multiplication:
                                calcs.Items.Insert(0, lastNumber.ToString() + " * " + newNumber.ToString() + " = " + SimpleMath.Mul(lastNumber, newNumber).ToString());
                                lastNumber = SimpleMath.Mul(lastNumber, newNumber);
                                showLabel.Content = lastNumber.ToString();
                                resultLabel.Content = showLabel.Content;
                                break;

                            case SelectedOperator.Division:
                                calcs.Items.Insert(0, lastNumber.ToString() + " / " + newNumber.ToString() + " = " + SimpleMath.Div(lastNumber, newNumber).ToString());
                                lastNumber = SimpleMath.Div(lastNumber, newNumber);
                                showLabel.Content = lastNumber.ToString();
                                resultLabel.Content = showLabel.Content;
                                break;
                        }

                        if (sender == plusButton)
                        {
                            selectedOperator = SelectedOperator.Addition;
                            showLabel.Content += " + ";
                        }

                        else if (sender == minusButton)
                        {
                            selectedOperator = SelectedOperator.Substraction;
                            showLabel.Content += " - ";
                        }

                        else if (sender == multipleButton)
                        {
                            selectedOperator = SelectedOperator.Multiplication;
                            showLabel.Content += " * ";
                        }

                        else if (sender == divideButton)
                        {
                            selectedOperator = SelectedOperator.Division;
                            showLabel.Content += " / ";
                        }
                    }

                }

                else
                {
                    if (double.TryParse(resultLabel.Content.ToString(), out lastNumber))
                    {
                        resultLabel.Content = "0";
                    }

                    if (showLabel.Content.ToString() != "0")
                        showLabel.Content += lastNumber.ToString();

                    else
                        showLabel.Content = lastNumber.ToString();

                    if (sender == plusButton)
                    {
                        selectedOperator = SelectedOperator.Addition;
                        showLabel.Content += " + ";
                    }

                    else if (sender == minusButton)
                    {
                        selectedOperator = SelectedOperator.Substraction;
                        showLabel.Content += " - ";
                    }

                    else if (sender == multipleButton)
                    {
                        selectedOperator = SelectedOperator.Multiplication;
                        showLabel.Content += " * ";
                    }

                    else if (sender == divideButton)
                    {
                        selectedOperator = SelectedOperator.Division;
                        showLabel.Content += " / ";
                    }
                }
            }
        }

        private void Sqrt_Click(object sender, RoutedEventArgs e)
        {
            if (One_Click())
            {
                if (double.TryParse(resultLabel.Content.ToString(), out lastNumber))
                {
                    result = SimpleMath.Root(lastNumber);
                    resultLabel.Content = result.ToString();
                }
            }
        }

        private void Sqrd_Click(object sender, RoutedEventArgs e)
        {
            if (One_Click())
            {
                if (double.TryParse(resultLabel.Content.ToString(), out lastNumber))
                {
                    result = SimpleMath.Sqrd(lastNumber);
                    resultLabel.Content = result.ToString();
                }
            }
        }
        private void DivX_Click(object sender, RoutedEventArgs e)
        {
            if (One_Click())
            {
                if (double.TryParse(resultLabel.Content.ToString(), out lastNumber))
                {
                    result = SimpleMath.Divx(lastNumber);
                    resultLabel.Content = result.ToString();
                }
            }
        }
        private void PercentButton_Click(object sender, RoutedEventArgs e)
        {
            if(One_Click())
            {
                if (resultLabel.Content.ToString() == "0")
                {
                    resultLabel.Content = "0";
                }

                else
                {
                    if (double.TryParse(resultLabel.Content.ToString(), out lastNumber))
                    {
                        lastNumber = lastNumber / 100;
                        resultLabel.Content = lastNumber.ToString();
                    }
                }
            }
        }
        private void AcButton_Click(object sender, RoutedEventArgs e)
        {
            if (resultLabel.Content.ToString() != "0")
            {
                showLabel.Content ="0";
                resultLabel.Content = "0";
            }

        }
        private void NumberButton_Click(object sender, RoutedEventArgs e)
        {
            Button currentButton = (Button)sender;

            if(check == 1)
            {
                resultLabel.Content = currentButton.Content.ToString();
                check = 0;
            }


            else if (resultLabel.Content.ToString() != "0")
            {
                resultLabel.Content += currentButton.Content.ToString();
            }

            else
            {
                resultLabel.Content = currentButton.Content.ToString();
            }
        }
            
        
        private void DelButton_Click(object sender, RoutedEventArgs e)
        {
            if(resultLabel.Content.ToString().Length==1)
            {
                resultLabel.Content = "0";
            }

            else
            {
                resultLabel.Content = resultLabel.Content.ToString().Substring(0, resultLabel.Content.ToString().Length - 1).ToString();
            }
        }
    }
}
