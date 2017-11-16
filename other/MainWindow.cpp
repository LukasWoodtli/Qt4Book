#include "MainWindow.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)

{

  setupModel();
  nameLabel = new QLabel(tr("Na&me:"));
  nameEdit = new QLineEdit();
  addressLabel = new QLabel(tr("&Address:"));
  addressEdit = new QTextEdit();
  ageLabel = new QLabel(tr("A&ge (in years):"));
  ageSpinBox = new QSpinBox();
  nextButton = new QPushButton(tr("&Next"));
  previousButton = new QPushButton(tr("&Previous"));

  nameLabel->setBuddy(nameEdit);
  addressLabel->setBuddy(addressEdit);
  ageLabel->setBuddy(ageSpinBox);

  mapper = new QDataWidgetMapper(this);
  mapper->setModel(model);
  mapper->addMapping(nameEdit, 0);
  mapper->addMapping(addressEdit, 1);
  mapper->addMapping(ageSpinBox, 2);

  connect(previousButton, SIGNAL(clicked()),
          mapper, SLOT(toPrevious()));
  connect(nextButton, SIGNAL(clicked()),
          mapper, SLOT(toNext()));
  connect(mapper, SIGNAL(currentIndexChanged(int)),
          this, SLOT(updateButtons(int)));


  QGridLayout *layout = new QGridLayout();
  layout->addWidget(nameLabel, 0, 0, 1, 1);
  layout->addWidget(nameEdit, 0, 1, 1, 1);
  layout->addWidget(previousButton, 0, 2, 1, 1);
  layout->addWidget(addressLabel, 1, 0, 1, 1);
  layout->addWidget(addressEdit, 1, 1, 2, 1);
  layout->addWidget(nextButton, 1, 2, 1, 1);
  layout->addWidget(ageLabel, 3, 0, 1, 1);
  layout->addWidget(ageSpinBox, 3, 1, 1, 1);
  setLayout(layout);


  mapper->toFirst();

}

MainWindow::~MainWindow()
{

}

void MainWindow::setupModel()
{
  model = new QStandardItemModel(5, 3, this);

  QStringList names;
  names << "Alice" << "Bob" << "Carol"
      << "Donald" << "Emma";

  QStringList addresses;
  addresses << "<qt>123 Main Street<br/>Market Town</qt>"
      << "<qt>PO Box 32<br/>Mail Handling Service"
      "<br/>Service City</qt>"
      << "<qt>The Lighthouse<br/>Remote Island</qt>"
      << "<qt>47338 Park Avenue<br/>Big City</qt>"
      << "<qt>Research Station<br/>Base Camp<br/>Big Mountain</qt>";

  QStringList ages;
  ages << "20" << "31" << "32" << "19" << "26";


  for (int row = 0; row < 5; ++row) {
    QStandardItem *item = new QStandardItem(names[row]);
    model->setItem(row, 0, item);
    item = new QStandardItem(addresses[row]);
    model->setItem(row, 1, item);
    item = new QStandardItem(ages[row]);
    model->setItem(row, 2, item);
  }
}

void MainWindow::updateButtons(int row)
{
  previousButton->setEnabled(row > 0);
  nextButton->setEnabled(row < model->rowCount() - 1);
}
