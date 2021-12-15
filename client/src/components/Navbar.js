import React, {useContext} from 'react'
import {NavLink, useNavigate} from 'react-router-dom'

export const Navbar = () => {
  const history = useNavigate()

  const logoutHandler = event => {
    event.preventDefault()
    history('/')
  }

  return (
    <nav>
      <div className="nav-wrapper teal darken-1" style={{ padding: '0 2rem' }}>
        <span className="brand-logo">ЕГЭ Решала</span>
        <ul id="nav-mobile" className="right hide-on-med-and-down">
          <li><NavLink to="/variants">Варианты</NavLink></li>
          <li><NavLink to="/questions">Вопросы</NavLink></li>
          <li><a href="/" onClick={logoutHandler}>Выйти</a></li>
        </ul>
      </div>
    </nav>
  )
}