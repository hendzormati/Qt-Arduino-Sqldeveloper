# Qt-Arduino-Sqldevelopers
# Share and Care Center Management Application

**Project Description:**

This repository contains a desktop application developed on Qt Creator for managing a Share and Care Center for the homeless. The application includes various features to efficiently handle the operations of the center, including personnel management, beneficiary management, consultation tracking, donation management (money), and stock management (physical donations that will be sold). The application ensures security and incorporates smart components such as an RFID sensor for user authentication, an LCD, and a 7-segment display. Moreover, to prioritize safety, the application also includes a flame sensor to detect fire occurrences in the facility.

## Table of Contents

- [Project Features](#project-features)
- [Installation](#installation)
- [Usage](#usage)
-  [Database Setup](#Database-Setup)
- [Technologies Used](#technologies-used)
- [Contributing](#contributing)
- [License](#license)

## Project Features

1. **Personnel Management:** This feature enables the administration to manage the staff working at the Share and Care Center. It includes functionalities such as adding new personnel, updating their information, and assigning roles and responsibilities.

2. **Beneficiary Management:** The application provides tools to manage the beneficiaries of the center effectively. This includes maintaining their profiles, recording personal information, and tracking their progress over time.

3. **Consultation Tracking:** To monitor the consultation services provided to the homeless, the application allows the staff to schedule and track appointments. It also provides a history of consultations for future reference.

4. **Donation Management (Money):** The application incorporates a system to manage monetary donations received by the center. It tracks the source, amount, and purpose of each donation and generates reports for transparency and accountability.

5. **Stock Management (Physical Donations):** For physical donations received, such as clothes, food, and other essential items, the application includes a stock management feature. It allows the staff to keep track of donated items, manage inventory, and ensure proper distribution.

6. **Security Features:** The application integrates smart components for enhanced security. It utilizes an RFID sensor for user authentication, ensuring that only authorized personnel can access sensitive information. Additionally, it includes an LCD and 7-segment display for displaying relevant information to the users.

7. **Fire Detection:** To ensure the safety of the center and its occupants, the application incorporates a flame sensor. In the event of a fire occurrence, the system detects the presence of flames and triggers appropriate emergency protocols.

## Installation

1. Clone the repository: `git clone https://github.com/your-repo.git`
2. Open the project in Qt Creator or your preferred IDE.
3. Configure the necessary dependencies and build the application.
4. Install any required libraries or packages specified in the project documentation.

## Database Setup

To set up the database for the Share and Care Center Management Application, follow these steps:

Locate the SQL File:

The SQL file required for the application is named ahminy.sql and is included in this project.
Configure Database Connection:

Open the connection.cpp file in your project.
Locate the section where the database connection is established.
Update the username and password to your Oracle account credentials.
Test Account:

When launching the application, you can log in using the following test credentials to explore the features:
Username: test
Password: test
Mailing Configuration:

If you wish to use the mailing feature, be sure to enter your own email information in the relevant section of the application.
Run the Application:

Ensure the database is set up and running.
Launch the Share and Care Center Management Application to start using the features.

## Usage

1. Launch the Share and Care Center Management Application.
2. Use the provided user interface to navigate through the various features.
3. Authenticate yourself using the RFID sensor or other designated authentication methods.
4. Utilize the personnel management feature to manage staff details, roles, and responsibilities.
5. Manage beneficiary profiles, including personal information and progress tracking.
6. Schedule and track consultations with the homeless using the consultation tracking feature.
7. Keep track of monetary donations, including sources, amounts, and purposes.
8. Manage physical donations, track inventory, and ensure proper distribution through the stock management feature.
9. Monitor the LCD and 7-segment display for important information and notifications.
10. In the event of a fire, rely on the flame sensor to trigger appropriate emergency protocols and ensure the safety of all individuals.

## Technologies Used

- Qt Creator: An integrated development environment for developing cross-platform applications.
- C++: The primary programming language used for building the desktop application.
- RFID Sensor: A smart component used

 for user authentication and access control.
- LCD and 7-Segment Display: Display components for presenting relevant information to the users.
- Flame Sensor: A safety feature that detects the presence of flames to trigger emergency protocols.
- Git: Version control system for tracking changes and collaborating with team members.

## Contributing

Contributions to enhance the functionality and usability of the Share and Care Center Management Application are welcome. To contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-feature`
3. Make your changes and commit them: `git commit -m 'Add some feature'`
4. Push to the branch: `git push origin feature/your-feature`
5. Submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
