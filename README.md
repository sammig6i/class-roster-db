<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->

<a name="readme-top"></a>

<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
<!-- [![Contributors][contributors-shield]][contributors-url] -->
<!-- [![Forks][forks-shield]][forks-url] -->

[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/sammig6i/class-roster-db">
    <img src="images/4315005.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Database for Class Roster</h3>

  <p align="center">
    An implementation of the class roster database for WGU C++ class. This is a simple program that can function as a database to store students in a class roster wth attributes like, ID, First and Last Name, Degree Program, and Ages.
    <br />
    <a href="https://github.com/sammig6i/class-roster-db"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    ·
    <a href="https://github.com/sammig6i/class-roster-db/issues">Report Bug</a>
    ·
    <a href="https://github.com/sammig6i/class-roster-db/issues">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->

## About The Project

![Product Name Screen Shot][product-screenshot]

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

- ![C++][C++] - version 11

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->

## Getting Started

These are steps for setting up the project locally.

### Prerequisites

- install g++ GNU compiler
  - install [Homebrew](https://brew.sh/) then run
  ```sh
  brew install gcc
  ```

### Installation

- Build project

```sh
make
```

- To clean up object files

```sh
make clean
```

- To run application locally

```sh
./rostr
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->

## Usage

- A new student can be created using the Student constructor and student's information.

```c++
Student student(studentID, firstName, lastName, emailAddress, age, daysToCompleteCourses, degreeProgram);
```

- A student can be added to the class roster.

```c++
Roster classRoster(5);
classRoster.addStudent(Student* student);
```

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->

## Contact

Your Name - [@sammig6i](https://twitter.com/sammig6i) - swghazzawi@gmail.com

Project Link: [https://github.com/sammig6i/class-roster-db](https://github.com/sammig6i/class-roster-db)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[contributors-shield]: https://img.shields.io/github/contributors/sammig6i/class-roster-db.svg?style=for-the-badge
[contributors-url]: https://github.com/sammig6i/class-roster-db/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/sammig6i/class-roster-db.svg?style=for-the-badge
[forks-url]: https://github.com/sammig6i/class-roster-db/network/members
[stars-shield]: https://img.shields.io/github/stars/sammig6i/class-roster-db.svg?style=for-the-badge
[stars-url]: https://github.com/sammig6i/class-roster-db/stargazers
[issues-shield]: https://img.shields.io/github/issues/sammig6i/class-roster-db.svg?style=for-the-badge
[issues-url]: https://github.com/sammig6i/class-roster-db/issues
[license-shield]: https://img.shields.io/github/license/sammig6i/class-roster-db.svg?style=for-the-badge
[license-url]: https://github.com/sammig6i/class-roster-db/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/sammighazzawi
[product-screenshot]: images/Screenshot.png
[C++]: https://img.shields.io/badge/C%2B%2B-000000?style=for-the-badge&logo=c%2B%2B
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com
